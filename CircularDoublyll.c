#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *start=NULL;

void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void show();

void main()
{
	int choice,ch;
	do
	{
	printf("1.insert_beg\n2.insert_end\n3.delete_beg\n4.delete_end\n5.show()\n6.insert_pos\n7.delete_pos\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			insert_beg();
			break;
		case 2:
			insert_end();
			break;
		case 3:
			delete_beg();
			break;
		case 4:
			delete_end();
			break;
		case 5:
			show();
			break;
		case 6:
			insert_pos();
			break;
		case 7:
			delete_pos();
			break;
		default:
			printf("Wrong Choice\n");
			break;
	}
	printf("Enter 1 for Continue\n");
	scanf("%d",&ch);
}while(ch==1);
}

void insert_beg()
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node)),*temp;
	int x;
	if(ptr==NULL)
	{
		printf("Overflow\n");
	}
	printf("Enter Value\n");
	scanf("%d",&x);
	ptr->data=x;
	if(start==NULL)
	{
		start=ptr;
		ptr->next=start;
		ptr->next=start;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
			temp->next=ptr;
			ptr->prev=temp;
			ptr->next=start;
			start->prev=ptr;
			start=ptr;
	}
}

void insert_end()
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node)),*temp;
	int x;
	if(ptr==NULL)
	{
		printf("Overflow\n");
	}
	printf("Enter Value\n");
	scanf("%d",&x);
	ptr->data=x;
	if(start==NULL)
	{
		start=ptr;
		ptr->next=start;
		ptr->next=start;
	}
	else
	{
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->prev=temp;
		ptr->next=start;
		start->prev=ptr;
		
	}
}

void delete_beg()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("Underflow\n");
	}
	if(start->next==start)
	{
		free(start);
		start=NULL;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=start->next;
		start->next->prev=temp;
		free(start);
		start=temp->next;
	}
}

void delete_end()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("Underflow\n");
	}
	if(start->next==start)
	{
		free(start);
		start=NULL;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->prev->next=start;
		start->prev=temp->prev;
		free(temp);
		
	}
}

void show()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			printf("\n%d",temp->data);
			temp=temp->next;
		}
		printf("\n%d",temp->data);
	}
}

void insert_pos()
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	struct node *temp;
	if(ptr==NULL)
	{
		printf("Overflow\n");
	}
	int pos,i,x;
	printf("Enter Pos\n");
	scanf("%d",&pos);
	temp=start;
	for(i=1;i<pos;i++)
	{
		temp=temp->next;
	}
	printf("Enter Value\n");
	scanf("%d",&x);
	ptr->data=x;
	ptr->next=temp;
	ptr->prev=temp->prev;
	temp->prev->next=ptr;
	temp->prev=ptr;	
}

void delete_pos()
{
	int pos,i;
	struct node *temp,*ptr;
	printf("Enter pos\n");
	scanf("%d",&pos);
	if(start==NULL)
	{
		printf("Empty List\n");
	}
	temp=start;
	for(i=1;i<pos;i++)
	{
		temp=temp->next;
	}
	ptr=temp;
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	printf("Deleted\n");
	
}

