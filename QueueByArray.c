#include<stdio.h>

int Queue[100],rear=-1,front=-1,size=100;

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
	int x;
	if(rear>=size-1)
	{
		printf("Overflow\n");
	}
	else
		{
			if(rear==-1 && front==-1)
			{
				rear=0;
				front=0;
			}
			else
			{
				rear=rear+1;
			}
			printf("Enter value\n");
			scanf("%d",&x);
			Queue[rear]=x;
		}
}

void deQueue()
{
	int x;
	if(front==-1||front>rear)
	{
		printf("Underflow\n");
	}
	else{
		x=Queue[front];
		printf("Element is :%d\n",x);
	
		if(front=rear)
		{
			front=-1;
			rear=-1;	
		}
		else
		{
			front=front+1;
		}
	}
	
}

void show()
{
	int i;
	if(front==-1||front>rear)
	{
		printf("Empty Queue\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",Queue[i]);
		}
	}
}
