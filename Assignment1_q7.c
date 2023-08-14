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
	
	count=p;
	
	printf("Enter the number of elements of matrix:");
	scanf("%d",&mat2.n);
	q=mat2.n;
	printf("Enter dimensions:");
	scanf("%d %d",&mat2.size_row,&mat2.size_col);
	for(i=0;i<q;i++){
		scanf("%d %d %d",&mat2.arr[i].row,&mat2.arr[i].col,&mat2.arr[i].val);
	}
	
	if(mat1.size_col==mat2.size_col && mat1.size_row==mat2.size_row){
		for(i=0;i<p;i++){
			for(j=0;j<q;j++){
				if(mat1.arr[i].col==mat2.arr[j].col && mat1.arr[i].row==mat2.arr[j].col){
					mat1.arr[i].val+=mat2.arr[i].val;
					mat2.arr[i].val=0;
				}
			}
		}
	
		for(i=0;i<q;q++){
			if(mat2.arr[i].val!=0){
				mat1.arr[count].row=mat2.arr[i].row;
				mat2.arr[count].col=mat2.arr[i].row;
				mat2.arr[count].val=mat2.arr[i].val;
				count++;
			}
		}
	
		printf("\n\n");
		
		for(i=0;i<count;i++){
			printf("%d %d %d\n",mat1.arr[i].row,mat1.arr[i].col,mat1.arr[i].val);
		}
    }else{
    	printf("Dimension Error\n");
	}
	return 0;	
	
	
}
