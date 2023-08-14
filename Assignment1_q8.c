#include <stdio.h>

typedef struct element{
	int row;
	int col;
	int val;
}element;

typedef struct matrix{
	element arr[20];
	int size_row;
	int size_col;
	int n;
}matrix;

int main(){
	matrix mat1,mat2;
	int i,p,q,j,count;
	
	printf("Enter the number of elements of matrix:");
	scanf("%d",&mat1.n);
	p=mat1.n;
	printf("Enter dimensions(Row/Col):");
	scanf("%d %d",&mat1.size_row,&mat1.size_col);
	for(i=0;i<p;i++){
		scanf("%d %d %d",&mat1.arr[i].row,&mat1.arr[i].col,&mat1.arr[i].val);
	}
	
	int* arr=(int*)calloc(mat1.size_row,sizeof(int));
	
	for(i=0;i<p;i++){
		j=mat1.arr[i].row;
		arr[j-1]+=1;		
	}
	
	printf("\n\n");
	for(i=0;i<mat1.size_row;i++){
		printf("%d:%d ",i+1,arr[i]);
	}
	
	return 0;
}
