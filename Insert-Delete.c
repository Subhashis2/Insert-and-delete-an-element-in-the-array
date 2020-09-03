//....Subhashis PAUL

#include<stdio.h>
#include<stdlib.h>
struct array
{
	int num;   int key;   int *arr;
};
int do_linear_search(struct array *elements);
int Insert_element(struct array *elements);
int Delete_element(struct array *elements);
int main()
{
struct array elements;
	int i,flag=0,choice;
	system("CLS");
	printf("\n\n Enter number of elements in the array :  ");
	scanf("%d",&elements.num);
	elements.arr = (int*)malloc(elements.num*sizeof(int));
	printf("\n Enter the elements : ");
	for(i=0;i<elements.num;i++)
	scanf("%d",elements.arr+i);
do
{
	system("CLS");
printf("\n *******************************************************");
printf("\n *                                                     *");
printf("\n *     1.   INSERT ELEMENT IN THE ARRAY (Type 1)       *");
printf("\n *                                                     *");
printf("\n *     2.   DELETE ELEMENT IN THE ARRAY (Type 2)       *");
printf("\n *                                                     *");
printf("\n *******************************************************");
printf("\n\n Please enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
	case 1:
		flag=1;
		Insert_element(&elements);
		break;
	case 2:
		flag=1;
		Delete_element(&elements);
		break;
	default:
		printf("\n Enter correct choice !!!!");
		flag = 0;
		sleep(2);
		break;
}
}while(flag!=1);
printf("\n\n The new array is :     ");
	for(i=0;i<elements.num;i++)
	printf("%d\t",*(elements.arr+i));
	free(elements.arr);
	printf("\n\n\n Type 'y' to try again or type 'n' to go to main menu : ");
	if(getch() == 'y')
	main();
	else
	exit(0);
return 0;
}

int do_linear_search(struct array *elements)
{
	int i,found=0;
	for(i=0;i<elements->num;i++)
	{
		if(elements->arr[i] == elements->key)
		{
			return i;
			found = 1;
			break;
		}
	}
	if(!found)
	return -1;
}

int Insert_element(struct array *elements)
{
printf("\n\n\n Enter the element to insert in the array :  ");
scanf("%d",&elements->key);
elements->num = elements->num + 1;
elements->arr = (int*)realloc(elements->arr,elements->num*sizeof(int));
elements->arr[elements->num] = elements->key;
}

int Delete_element(struct array *elements)
{
	int pos,i;
printf("\n\n\n Enter the element to insert in the array :  ");
scanf("%d",&elements->key);
pos = do_linear_search(elements);
	if(pos == -1)
		{
			printf("\n\n Element is not found in the array !!");
			sleep(2);
			main();
		}
	else
		{
			elements->num = elements->num - 1;
			for(i=pos; i<elements->num; i++)
			{
				elements->arr[i] = elements->arr[i+1];  
			}
		}
}
