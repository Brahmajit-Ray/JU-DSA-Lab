#include <stdio.h>
#include <stdlib.h>

void printArr(int* arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void printStar(){
	int i;
	for(i=0;i<20;i++){
		printf("*");
	}
	printf("\n");
}

void bubble_sort(int* arr,int n){
	int i,j;  
    for (i = 0;i<n-1;i++) {  
		for (j = 0; j < n - i - 1; j++) {  
      		if (arr[j]>arr[j+1]){  
        	int temp=arr[j];  
       		arr[j]=arr[j+1];  
        	arr[j+1]=temp;  
       }
	  printArr(arr,n);
    }  
  }  
}

void selection_sort(int* arr,int n) {  
    int i, j, small;  
      
    for(i=0;i<n-1;i++){  
        small = i;
        for (j = i+1; j < n; j++){
        if (arr[j] < arr[small])  
            small = j;  
        }
    int temp = arr[small];  
    arr[small] = arr[i];  
    arr[i] = temp;  
    printArr(arr,n);
    }  
}  

void insertion_sort(int* arr, int n) {  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = arr[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= arr[j])   
        {    
            arr[j+1] = arr[j];     
            j = j-1;    
        }    
        arr[j+1] = temp;  
		printArr(arr,n) ;
    }  
}


void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2];  
      
      
    for ( i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for ( j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0;   
    j = 0;  
    k = beg;  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void merge_sort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        merge_sort(a, beg, mid);  
        merge_sort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}  
  
  
void heapify(int a[], int n, int i)  
{  
    int largest = i; 
    int left = 2 * i + 1;   
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])  
        largest = left;  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    if (largest != i) {   
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}  
  
void heap_sort(int a[], int n)  
{   int i;
    for ( i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
     
    for ( i = n - 1; i >= 0; i--) {   
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}  


int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; 
    int i = (start - 1),j;  
  
    for ( j = start; j <= end - 1; j++)  
    {  
        
        if (a[j] < pivot)  
        {  
            i++;  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  
  
  
void quick_sort(int a[], int start, int end)
{  
    if (start < end)  
    {  
        int p = partition(a, start, end); 
        quick_sort(a, start, p - 1);  
        quick_sort(a, p + 1, end);  
    }  
}  
  

int main(){
	
	int dec,val,n,i;
	
	printf("Enter number of elements of array:\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter 1 for bubble sort:\n");
	printf("Enter 2 for selection sort:\n");
	printf("Enter 3 for insertion sort:\n");
	printf("Enter 4 for merge sort:\n");
	printf("Enter 5 for heap sort:\n");
	printf("Enter 6 for quick sort:\n");
	
	scanf("%d",&val);
	
	switch(val){
		case 1:
			bubble_sort(arr,n);
			
		case 2:
			selection_sort(arr,n);
			
		case 3:
			insertion_sort(arr,n);
			
		case 4:
			merge_sort(arr,0,n-1);
			printArr(arr,6);
			
		case 5:
			heap_sort(arr,n);
			printArr(arr,6);
			
		case 6:
			quick_sort(arr,0,n);
			printArr(arr,6);
			
	}
	
	return 0;
	
}
