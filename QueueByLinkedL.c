#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *front=NULL,*rear=NULL;

void enQueue();
void deQueue();
void show();

void main()
{
	int choice,ch;
	do
	{
	printf("1.Insert\n2.Delete\n3.show\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			enQueue();
			break;
		case 2:
			deQueue();
			break;
		case 3:
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


void enQueue()
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	int x;
	if(ptr==NULL)
	{
		printf("Overflow\n");
	}
	printf("Enter Value\n");
	scanf("%d",&x);
	ptr->data=x;
	if(front==NULL && rear==NULL)
	{
		ptr->next=NULL;
		front=ptr;
		rear=ptr;
	}
	else
	{
		ptr->next=NULL;
		rear->next=ptr;
		rear=ptr;
	}
}

void deQueue()
{
	struct node *temp;
	if(front==NULL)
	{
		printf("Underflow\n");
	}
	else{
	temp=front;
	front=front->next;
	printf("Deleting front is %d\n",temp->data);
	free(temp);
}
}

void show()
{
	if(front==NULL && rear==NULL)
	{
		printf("Empty Queue\n");
	}
	struct node *temp;
	temp=front;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
