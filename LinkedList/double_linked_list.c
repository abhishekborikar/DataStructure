#include<stdio.h>
#include<malloc.h>
typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}node;

node *next,*head,*last,*sort;
node *getnewnode(int data){
	node *newnode = (node *)malloc(sizeof(node));
	newnode->left=NULL;
	newnode->data=data;
	
}
void insert(){
	int data;
	node *temp;
	temp=head;
	printf("Enter an element\n");
	scanf("%d",&data);
	node *newnode=getnewnode(data);
	if(next==NULL){
		next=newnode;
		head=next;
	}
	else{
		while(temp->right!=NULL){
		temp=temp->right;
	}
	temp->right=newnode;
	newnode->left=temp;
	newnode->right=NULL;
	last=newnode;	
	}

}
void display(){
	node *temp;
	temp=head;
	while(temp!=NULL){
		printf("%d\t",temp->data);	
		temp=temp->right;
	}
//	printf("%d\t",temp->data);
	printf("\n");
	return;
}
void rev(){
	
	
	node *temp1;
	temp1=last;
	while(temp1->left!=NULL){
		printf("%d\t",temp1->data);
		temp1=temp1->left;
	}
	printf("%d\n",temp1->data);
	return;
	
}
void delq(){
	node *temp;
	temp = head;
	head=temp->right;
	temp->right=NULL;
	free(temp);
	return;
}
void dels(){
	node *temp;
	temp=last;
	last=temp->left;
	temp->left=NULL;
	free(temp);
	return;
}
main(){
	int choice,cont=0;

	
	while(cont==0){
		printf("1\t->\tinsert\n2\t->\tdisplay\n3\t->\tdisplay Reverse\n4\t->\tdelete first\n5\t->\tdelete last\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				insert();
				break;
			}
			case 2:{
				display();
				break;
			}
			case 3:{
				rev();
				break;
			}
			case 4:{
				delq();
				break;
			}
			case 5:{
				dels();
				break;
			}
		}
	
	}
}
