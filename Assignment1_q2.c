#include <stdio.h>

int main(){
	int n,i,swap;
	printf("Enter array length:");
	scanf("%d",&n);
	int arr[n];
	
	for(i=0;i<=n-1;i++){
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<=(n-1)/2;i++){
		swap=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=swap;
	}
	
	for(i=0;i<=n-1;i++){
		printf("%d",arr[i]);
	}
	
	return 0;
}
