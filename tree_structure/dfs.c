#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    node* left;
    node* right;
}node;

struct node* root;
struct node *dnode, *temp;

struct node* insert(struct node* r, int data);
void inOrder(struct node* r);
void preOrder(struct node* r);
void postOrder(struct node* r);
int countNode(struct node *t);
int countLeaveNode(node *t);
int height(node *t);
node *searchNode(node *t,int n);
void traversal();
node *deleteNode(node *t,int search);
node *minValue(node *t);
void topView(node *t);
node *lca(node *t,int min,int max);









int main()
{
    root = NULL;
    int n, v;

    printf("How many data's do you want to insert ?\n");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Data %d: ", i+1);
        scanf("%d", &v);
        root = insert(root, v);
    }

    traversal();
	
	printf("Numbers of Node\n");
	printf("%d\n",countNode(root));

	printf("Numbers of Leaf Nodes\n");
	printf("%d\n",countLeaveNode(root));
	
	printf("Height\n");
	printf("%d\n",height(root));
	
	printf("Enter two values\n");
	int p,q;
	scanf("%d%d",&p,&q);
	printf("%d\n",root)
	;node *te;
	te = lca(root,p,q);
	if(te==NULL) printf("NULL");
	else printf("%d",te);
	
//	printf("Search Node\n");
//	int search;
//	scanf("%d",&search);
//	printf("%d",searchNode(root,search)->value);
//	if(searchNode(root,search)!=NULL)
//	dnode=searchNode(root,search);
//	else
//	printf("NULL");

//	inOrder(deleteNode(root,search));
//	topView(root);
    return 0;
}

void traversal(){
	printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");
}
struct node* insert(struct node* r, int data)
{
    if(r==NULL)
    {
        r = (struct node*) malloc(sizeof(struct node));
        r->value = data;
        r->left = NULL;
        r->right = NULL;
    }
    else if(data < r->value){
        r->left = insert(r->left, data);
    }
    else {
        r->right = insert(r->right, data);
    }
    return r;

}

void inOrder(struct node* r)
{
    if(r!=NULL){
        inOrder(r->left);
        printf("%d", r->value);
        inOrder(r->right);
    }
}

void preOrder(struct node* r)
{
    if(r!=NULL){
        printf("%d ", r->value);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node* r)
{
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ", r->value);

    }
}

int countNode(node *t){
	if(t!=NULL) return (1+countNode(t->left)+countNode(t->right));
	else return 0;	
}

int count=0;

int countLeaveNode(node *t){	
	if(t!=NULL){
		if((t->left==NULL)&&(t->right==NULL))
	return ++count;
	countLeaveNode(t->left);
	countLeaveNode(t->right);	
	}
}

int l,r;
int height(node *t){
	if(t==NULL) return 0;
	if((t->left==NULL) && (t->right==NULL)) return 0;
	
	l = height(t->left);
	r = height(t->right);
	return ((l>=r?l:r)+((t->left!=NULL || t->right!=NULL)?1:0));
}


node *minValue(node *t){
	
	while(t->left!=NULL){
		t = t->left;
	}
	return t;
}

//void maxValue(node *t){
//	c = t;
//	while(c->right!=NULL){
//		p = c;
//		c = c->right;
//	}
//}
node *deleteNode(node *t,int search){
	
	if(t==NULL) return t;
	
	if(search<t->value)
		t->left = deleteNode(t->left,search);
	else if(search>t->value)
		t->right = deleteNode(t->right,search);
	else{
		
		//only one child 
		if(t->left==NULL){
			temp = t->right;
			free(t);
			return temp;	
		}
		else if(t->right==NULL){
			temp = t->left;
			free(t);
			return temp;
		}
		
		temp = minValue(t->right);
		t->value = temp->value;
		t->right = deleteNode(t->right,temp->value);
	}
	
	return t;
	
	
	
//	//leaf node
//	if(t->left==NULL && t->right==NULL){
//		free(t);
//	}
//	//left child
//	else if(t->left!=NULL){
//		maxValue(t->left);
//		if(c->left!=NULL){
//			p->right = c->left;
//			c->left = NULL;
//		}
//		dnode->value = c->value;
//		free(c);
//	}
//	//right child
//	else if(t->right!=NULL){
//		minValue(t->right);
//		if(c->right!=NULL){
//			p->left = c->right;
//			c->right = NULL;
//		}
//		dnode->value = c->value;
//		free(c);
//	}
//	
//	traversal();
}

node *searchNode(node *t,int n){
	
	if(t==NULL) return NULL;
	
	if(n>(t->value)){
		searchNode(t->right,n);
	}
	else if(n<(t->value)){
		searchNode(t->left,n);
	}
	else{
		return t;
	}
}


void topView(node *t) {
   
    static node* temp = t;
   if(t == NULL)
    {
    return;
   }
   topView(t->left);
   printf("%d ",t->value);
   if(t == temp)
      {
      t = t->right;//Don't want to print the root element twice
      while(t != NULL)
         {
         printf("%d ",t->value);
         t = t->right;
      }
   } 
    
}
int i=0;
node *lca(node *t, int v1,int v2){
	if(!t) return NULL;
	if(i==0){
         i =1;
        lca(t,v1>v2?v1:v2,v1<v2?v1:v2);
    }
    if(v1>t->value && v2 < t->value){
    	printf("%d%d%d",v1,v2,t->value);
		return t;	
	} 
//    else if(v1 < t->value && v2< t->value) {
//    	return lca(t->left,v1,v2);
//	}
//    else  return lca(t->right,v1,v2);
    
    
}
