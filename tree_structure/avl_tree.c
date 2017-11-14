// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>
 
//tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
 
// A utility function to get maximum of two integers
int max(int a, int b);
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
//function to allocate the new node
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
 
//Right Rotation of the sub tree
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Rotate
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    
    return x;
}
 
//Left Rotate Sub Tree
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // rotate
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    
    return y;
}

 
 //insert in the tree
struct Node* insert(struct Node* node, int key)
{
    //normal binary search tree insertation
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
 	
 	
    //update the height of the previous node
    node->height = 1+ max(node->left->height,node->right->height);
 
   //get the balance of the previous node
    int balance = (node == NULL) ? 0 : height(node->left) - height(node->right);
 
    // following are the conditions for unbalanced node
 
    // Left Left
    if (balance > 1 && key < node->left->key){
    	
		return rightRotate(node);
	}
        
 
    // Right Right 
    if (balance < -1 && key > node->right->key){
    	printf("%d\t%d\n",node->right->key,key);
    	return leftRotate(node);
	}
        
 
    // Left Right
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    
    return node;
}
 
//print the pre order traversal
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        
     	printf("%d\t%d\n ", root->key,root->height);
     	preOrder(root->left);
	    preOrder(root->right);
    }
}
 

int main()
{
  struct Node *root = NULL;
 
//input for the tree
  root = insert(root, 5);
  root = insert(root, 9);
  root = insert(root, 2);
  root = insert(root, 4);
  root = insert(root, 10);
  root = insert(root, 6);

 
  printf("Preorder Traversal\n");
  preOrder(root);
 
  return 0;
}
