#include<stdio.h>
#include<stdlib.h>


#define MAX 20
#define MAX_HEAP 0
#define MIN_HEAP 1

void max_heapify(int a[],int root,int heapsize){
	int l = 2*root+1;
	int r = (2*root)+2;
	int largest = 0;
	
	if(l>heapsize)
		return;
	//get largest among three
	//first compare left child and parent
	if(a[root]<a[l] && l<=heapsize)
		largest = l;
	else
		largest = root;
	
	if(a[r]>a[largest] && r <= heapsize)
		largest = r;
	
	//final step to compute
	if(largest!=root){
		int temp;
		
		//x change the values
		temp = a[root];
		a[root] = a[largest];
		a[largest] = temp;
		
		max_heapify(a,largest,heapsize);
	}
}

void min_heapify(int a[],int root,int heapsize){
	int l = 2*root+1;
	int r = (2*root)+2;
	int largest = 0;
	
	if(l>heapsize)
		return;
	//get largest among three
	//first compare left child and parent
	if(a[root]>a[l] && l<=heapsize)
		largest = l;
	else
		largest = root;
	
	if(a[r]<a[largest] && r <= heapsize)
		largest = r;
	
	//final step to compute
	if(largest!=root){
		int temp;
		
		//x change the values
		temp = a[root];
		a[root] = a[largest];
		a[largest] = temp;
		
		min_heapify(a,largest,heapsize);
	}
}

//0 -> build max heap
//1 -> build min heap
//default -> max heap
int* build_heap(int a[],int n,int max_min){
	int heap_size = n;
	int i=0,flag=0;
	
	//build max or min heap
	if(max_min==MAX_HEAP){
		for(i = heap_size/2 ; i >= 0; i--){
		max_heapify(a,i,heap_size);
		}	
	}
	else{
		for(i = heap_size/2 ; i >= 0; i--){
		min_heapify(a,i,heap_size);
		}
	}
	
	return a;	
}

int main(){
	
	//get the size of heap
	printf("Enter the number of elements\n");
	int n;
	scanf("%d",&n);
	
	//initialize the array with max size
	int *a = (int*)calloc(MAX,sizeof(int));
	
	//input the array
	if(n>20){
		printf("Sorrry, You have an oversize\n");
	}
	else{
	
		int i=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		
		build_heap(a,n,0);
		
		//print the max heap
		for(i=1;i<=n;i++)
			printf("%d\t",a[i]);
	}
	
	return 0;
}
