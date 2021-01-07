#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
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
	struct node *ptr =(struct node*)malloc(sizeof(struct node));
	int x;
	if(ptr==NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		printf("Enter Value\n");
		scanf("%d",&x);
		ptr->data=x;
		if(start==NULL)
		{
			start=ptr;
		}
		else
		{
		ptr->next=start;
		start=ptr;
	}
	}
	
}

void insert_end()
{
	struct node *ptr =(struct node*)malloc(sizeof(struct node));
	struct node *temp;
	int x;
	if(ptr==NULL)
	{
		printf("Overflow\n");
	}
	else{
		printf("Enter Value\n");
		scanf("%d",&x);
		ptr->data=x;
		ptr->next=NULL;
		if(start==NULL)
		{
			start=ptr;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=NULL;
		}
}
		
}

void delete_beg()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("underflow\n");
	}
	else
	{
		temp=start;
		start=temp->next;
		printf("Node deleting.. at begining is %d\n",temp->data);
		free(start);
		printf("Node deleted at begining\n");
	}
}

void delete_end()
{
	struct node *temp,*preptr;
	if(start==NULL)
	{
		printf("Underflow\n");
	}
	else
	{
		if(start->next==NULL)
		{
			free(start);
			start=NULL;
			
		}
		else
		{
		temp=start;
		while(temp->next!=NULL)
		{
			preptr=temp;
			temp=temp->next;
		}
		preptr->next=NULL;
		printf("Node deleting.. at end is %d\n",temp->data);
		free(temp);
		printf("Node deleted at end\n");
	}
}
}

void show()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("Empty List\n");
		return;
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("\n%d\n",temp->data);
			temp=temp->next;
		}
	}
}

void insert_pos()
{
	struct node *ptr =(struct node*)malloc(sizeof(struct node));
	struct node *temp,*preptr;
	int pos,i,x;
	printf("Enter pos \n");
	scanf("%d",&pos);
	temp=start;
	for(i=1;i<pos;i++)
	{
		preptr=temp;
		temp=temp->next;
	}
	printf("Enter value\n");
	scanf("%d",&x);
	ptr->data=x;
	preptr->next=ptr;
	ptr->next=temp;
	
}

void delete_pos()
{
	struct node *temp,*preptr;
	int pos,i,x;
	printf("Enter pos \n");
	scanf("%d",&pos);
	temp=start;
	for(i=1;i<pos;i++)
	{
		preptr=temp;
		temp=temp->next;
	}
	preptr->next=temp->next;
	free(temp);
}

