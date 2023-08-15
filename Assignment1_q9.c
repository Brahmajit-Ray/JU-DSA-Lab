#include <stdio.h>

int main(){
	int m,n,i,j;
	
	printf("Enter the number of rows:");
	scanf("%d",&m);
	printf("Enter the number of cols:");
	scanf("%d",&n);
	printf("\n");
	
	int arr[m][n],arr2[m*n];
	
	for(i=0;i<m;i++){
		printf("Enter the elements of row:");
		for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			arr2[i*n+j]=arr[i][j];
		}
	}
	
	printf("\n\n");
	printf("Elements of 1D array:\n");
	
	for(i=0;i<m*n;i++){
		printf("%d ",arr2[i]);
	}
	
	return 0;
}
