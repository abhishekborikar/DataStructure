#include "build_max_heap.cpp"

int* heap_sort(int*,int);

int main(){
	
	int a[] = {1,2,3,4,5};
	int length=sizeof(a)/sizeof(a[0]);
	//receiver
	int *m = (int*)calloc(length,sizeof(int));
	int *n = (int*)calloc(length,sizeof(int));
	//build the max heap
	m = build_max_heap(a,length);
	
	int i;
	for(i =0;i<length;i++)
		printf("%d\t",m[i]);
		
	printf("\n");
	//heap sort
	n = heap_sort(m,length);
	for(i = 0 ;i < 5 ; i++)
		printf("%d\t",n[i]);
	
	
}

int* heap_sort(int a[],int heap_size){
	
	int i,temp;
	int length = heap_size;
	
	//donot decrement i in for loop since it reduce size of array after calling 
	//max_heapify
	for(i=heap_size-1;i>=0;){
		
		//x change first element with last
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
	
		//eliminate the last element i.e. reduce the size of heap
		i--;
		max_heapify(a,0,i);
	}
	
	return a;
}
