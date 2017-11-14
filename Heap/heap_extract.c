//comment this line if executed program individually
//and uncomment the main class
#include "build_heap.cpp"

int heap_extract_max(int *,int );
int* heap_increase_key(int*, int, int);

int flag = 0;//1 not changed, 0 changed

//int main(){
//
//	int a[] = {1,2,3,4,5};
//	int length = sizeof(a)/sizeof(a[0]);
//	int *m = (int*)calloc(5,sizeof(int));
//	
//	m = build_heap(a,length,0);
//	
//	int max = heap_extract_max(m,length);
//	printf("%d\n",max);
//	int i;
//	for(i=0;i<length-1;i++){
//		printf("%d\t",m[i]);
//	}
//	
//	printf("\n");
//	//replace node
//	int key = 200,index = 1;
//	m = heap_increase_key(m,index, key);
//	if(flag==0){
//		for(i=0;i<length-1;i++)
//		printf("%d\t",m[i]);
//	
//	}	
//	
//}

//get the max value from the heap and delete
//example input 5,4,3,2,1
//output 4,3,2,1
//required a[] must be max_heap
int heap_extract_max(int a[],int n){
	
	int heap_size = n;
	
	//underflow condition
	if(heap_size<1){
		return -99999;
	}
	int max = a[0];
	a[0] = a[heap_size];
	
	heap_size--;
	
	max_heapify(a,0,heap_size);
	return max;
	
}

//required a[] must be min_heap
int heap_extract_min(int a[],int n){
	
	int heap_size = n;
	
	//underflow condition
	if(heap_size<1){
		return -99999;
	}
	int min = a[0];
	a[0] = a[heap_size];
	
	heap_size--;
	
	min_heapify(a,0,heap_size);
	return min;
	
}

//required a[] must be max_heap
//increase the key value or value of the node
//replace a node with higher value
//index -> index of the node where value need to xchange
int* heap_increase_key(int a[],int index,int key){
	
	//if key is less than a[i] it could not fit here 
	//so gives error
	if(key<a[index]){
		flag = 1;
		return a;
	}
	
	//replace the index node with key
	a[index] = key;
	
	int temp;
	//check with the parent
	while(index>0 && a[index/2]<a[index]){
		temp = a[index];
		a[index] = a[index/2];
		a[index/2] = temp;
		
		index/=2;
	}
	
	return a;
}
