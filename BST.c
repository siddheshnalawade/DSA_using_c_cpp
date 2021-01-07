#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root =NULL;

struct node* createnode_and_insert(int);
struct node* insert_node(struct node*,struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node* search(struct node*,int);
int height(struct node*);
int count_nodes(struct node*);
int max(int,int);
struct node* delete_node(struct node*,int);
struct node* largest_node(struct node*);
struct node* smallest_node(struct node*);


void main()
{
	createnode_and_insert(10);
	createnode_and_insert(8);
	createnode_and_insert(9);
	createnode_and_insert(7);
	createnode_and_insert(12);
	createnode_and_insert(13);
	createnode_and_insert(11);
	createnode_and_insert(4);
	printf("Inorder: ");
	inorder(root);
	printf("\n");
	printf("Preorder: ");
	preorder(root);
	printf("\n");
	printf("Postorder: ");
	postorder(root);
	printf("\n");
	search(root,4);
	printf("\nHeight of tree is %d and number of nodes are %d \n",height(root),count_nodes(root));
	printf("largest node : %d\n",largest_node(root)->data);
	printf("smallest node :%d\n",smallest_node(root)->data);
	
	delete_node(root,8);
	
	printf("Inorder: ");
	inorder(root);
	printf("\n");
	printf("Preorder: ");
	preorder(root);
	printf("\n");
	printf("Postorder: ");
	postorder(root);
	printf("\n");
	search(root,4);
	printf("\nHeight of tree is %d and number of nodes are %d \n",height(root),count_nodes(root));
	printf("largest node : %d\n",largest_node(root)->data);
	printf("smallest node :%d\n",smallest_node(root)->data);
	
	
	


	
	
}

struct node* createnode_and_insert(int data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	if(new_node!=NULL)
	{
		new_node->data=data;
		new_node->left=NULL;
		new_node->right=NULL;
		insert_node(root,new_node);
	
	}
	else
	{
		printf("Overflow\n");
	}
}

struct node* insert_node(struct node* head,struct node *new_node)
{
	if(head==NULL)
	{
		root=new_node;
	}
	else if(head->left==NULL && new_node->data<=head->data)
	{
		head->left=new_node;
	}
	else if(head->right==NULL && new_node->data>head->data)
	{
		head->right=new_node;
	}
	else if(new_node->data<=head->data)
	{
		head->left=insert_node(head->left,new_node);
	}
	else
	{
		head->right=insert_node(head->right,new_node);
	}
}

struct node* delete_node(struct node* head,int val)
{
	if(head==NULL)
	{
		return NULL;
	}
	else if(head->data==val)
	{
		if(head->left==NULL && head->right==NULL)
		{
			free(head);
			head=NULL;
		}
		else if(head->left==NULL)
		{
			struct node* temp=head;
			head=head->right;
			free(temp);
		}
		else if(head->right==NULL)
		{
			struct node* temp=head;
			head=head->left;
			free(temp);
		}
		else
		{
			struct node* temp = smallest_node(head->right);
			head->data=temp->data;
			head->right=delete_node(head->right,temp->data);
		}
		
	}
	else if(val<head->data)
	{
		head->left=delete_node(head->left,val);
	}
	else
	{
		head->right=delete_node(head->right,val);
	}
	return head;
}

void inorder(struct node *head)
{
	if(head==NULL)
	{
		return;
	}
	
	inorder(head->left);
	printf("%d ",head->data);
	inorder(head->right);
}

void preorder(struct node* head)
{
	if(head==NULL)
	{
		return;
	}
	
	printf("%d ",head->data);
	preorder(head->left);
	preorder(head->right);
}

void postorder(struct node* head)
{
	if(head==NULL)
	{
		return;
	}
	
	postorder(head->left);
	postorder(head->right);
	printf("%d ",head->data);
}

struct node* search(struct node *head,int val)
{
	if(head==NULL)
	{
		printf("%d Not found\n",val);
	}
	else if(head->data==val)
	{
		printf("value %d found at %u \n",val,head);
	}
	else if(val<head->data)
	{
		search(head->left,val);
	}
	else
	{
		search(head->right,val);
	}
}

int height(struct node* head)
{
	if(head==NULL)
	{
		return -1;
	}
	else
	{
		return 1+max(height(head->left),height(head->right));
		
	}
}

int count_nodes(struct node* head)
{
	if(head==NULL)
	{
		return 0;
	}
	else
	{
		return 1+count_nodes(head->left)+count_nodes(head->right);
	}
}

int max(int x,int y)
{
	int z = x>y ? x : y;
	return z;
}

struct node* largest_node(struct node* head)
{
	if(head==NULL)
	{
		return NULL;
	}
	else if(head->right==NULL)
	{
		return head;
	}
	else
	{
		largest_node(head->right);
	}
}

struct node* smallest_node(struct node* head)
{
	if(head==NULL)
	{
		return NULL;
	}
	else if(head->left==NULL)
	{
		return head;
	}
	else
	{
		smallest_node(head->left);
	}
}
