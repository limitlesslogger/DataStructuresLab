#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}nd;
nd* front=NULL;
nd* end=NULL;
nd* create_node()
{
	nd* new_node=(nd*)malloc(sizeof(nd));
	new_node->left=NULL;
	new_node->right=NULL;
	printf("Enter data to be inserted\n");
	scanf("%d",&new_node->data);
	return new_node;
}
void insert_begin()
{
	nd* new_node=create_node();
	if(front==NULL)
	{
		front=new_node;
		end=new_node;
		end->right=front;
		front->left=end;
	}
	else
	{
		new_node->right=front;
		new_node->left=end;
		end->right=new_node;
		front=new_node;
	}
}
void insert_end()
{
	nd* new_node=create_node();
	if(front==NULL)
	{
		front=new_node;
		end=new_node;
		end->right=front;
		front->left=end;
	}
	else
	{
		new_node->right=front;
		new_node->left=end;
		end->right=new_node;
		end=new_node;
	}
}
void delete_begin()
{
	nd* ptr=front;
	if(ptr==NULL)
	{
		printf("No elements to delete\n");
	}
	else
	{
		end->right=front->right;
		front->right->left=end;
		front=front->right;
	}
	free(ptr);
}
void delete_end()
{
	nd* ptr=end;
	if(ptr==NULL)
	{
		printf("No elements to delete\n");
	}
	else
	{
		end->left->right=front;
		front->left=end->left;
		end=end->left;
	}
	free(ptr);
}
void display()
{
	nd* temp=front;
	if(temp==NULL)
	{
		printf("Empty\n");
	}
	else
	{
		do
		{
			printf("%d ",temp->data);
			temp=temp->right;
		}
		while(temp!=front);
	}
}
void main()
{
	printf("Enter\n1 to insert at begining\n2 to insert at end\n3 to delete from begining\n4 to delete from end\n5 to display\n");
	int op;
	char ch='y';
	while(ch=='y')
	{
		printf("Enter choice from 1 to 5\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			insert_begin();
			break;
			case 2:
			insert_end();
			break;
			case 3:
			delete_begin();
			break;
			case 4:
			delete_end();
			break;
			case 5:
			display();
			break;
			default:
			printf("Invalid choice\n");
		}
		printf("Do you wish to perform more operations\n");
		scanf(" %c",&ch);
	}
}