#include<stdio.h>
#include<malloc.h>
void insert();
void del();
void display();

//typedef struct Node
//{
//	int data;
//	struct node *next;
//}node;

typedef struct Node
{
  int data;
  struct Node *next;	
}node;
node *head;

void insert()
{
	node *newnode = (node *)malloc(sizeof(node));
	node *temp;
	temp = head;
	if(temp==NULL)
	{
		
		head = newnode;
		temp = head;
	}
	else
	{
		
		while(temp->next!=NULL)
		temp=temp->next;
	}
	temp->next = newnode;
	int data;
	printf("Enter an element\n");
	scanf("%d",&data);
	newnode->data = data;
	newnode->next = NULL;
	display();
	return;
}

void del()
{
	node *temp;
	temp = head;
	if(temp==NULL)
	{
		printf("list is empty");
		return;
	}
	else
	{
		while((temp->next)->next!=NULL)
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
	display();
}


void display()
{
	node *temp;
	temp = head;
	while(temp->next!=NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data);
	return ;
}
int main()
{
	int c,input;
	do
	{
		printf("Enter the cmd\n");
		printf("0\tto continue\n1\tinsert\n2\tdelete\n3\tdisplay\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
			{
				insert();
				break;
			}
			case 2:{
				del();
				break;
			}
		}
		printf("Do you want to continue??\n");
		scanf("%d",&c);
	}while(c==0);
	return 0;
}
