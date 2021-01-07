#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};

struct node *TOP=NULL;

void push();
void pop();
void show();
int peek();


void main()
{int choice,T,ch;
	do
	{
	printf("1.push\n2.pop\n3.peek\n4.show\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			T=peek();
			printf("Top Ele is :%d\n",T);
			break;
		case 4:
			show();
			break;
		default:
			printf("Wrong Choice\n");
			break;
	}
	printf("Enter 1 for Continue\n");
	scanf("%d",&ch);
}while(ch==1);
}

void push()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	int x;
	if(ptr==NULL)
	{
		printf("Overflow\n");
	}
	printf("Enter Value\n");
	scanf("%d",&x);
	ptr->data=x;
	if(TOP==NULL)
	{
		ptr->next=NULL;
		TOP=ptr;
	}
	else
	{
		ptr->next=TOP;
		TOP=ptr;
	}
}

void pop()
{
	struct node *temp;
	if(TOP==NULL)
	{
		printf("Underflow\n");
	}
	temp=TOP;
	TOP=TOP->next;
	printf("TOP is deleting %d\n",temp->data);
	free(temp);
	
}

int peek()
{
	if(TOP==NULL)
	{
		printf("Empty Stack\n");
	}
	int x;
	x=TOP->data;
	return x;
}

void show()
{
	if(TOP==NULL)
	{
		printf("Empty Stack\n");
	}
	struct node *temp;
	temp=TOP;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	
}
