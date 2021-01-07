#include<stdio.h>

int Stack[100],size=100,Top=-1;

void push();
void pop();
int peek();
void show();

void main()
{
	int choice,T,ch;
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
	int x;
	printf("Enter Value\n");
	scanf("%d",&x);
	if(Top>=size-1)
	{
		printf("Overflow\n");
	}
	else
	{
		Top=Top+1;
		Stack[Top]=x;
	}
}

void pop()
{
	int val;
	if(Top<=-1)
	{
		printf("Underflow\n");
		
	}
	else
	{
		val=Stack[Top];
		printf("Stack Top is :%d\n",val);
		Top=Top-1;
	}
}

int peek()
{
	if(Top<=-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
	int val;
	val=Stack[Top];
	return val;
}
}

void show()
{
	int i;
	if(Top<=-1)
	{
		printf("Stack is empty\n");
	}
	else{
	for(i=Top;i>=0;i--)
	{
		printf("%d\n",Stack[i]);
	}
}
}


