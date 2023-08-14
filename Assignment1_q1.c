#include <stdio.h>

int main(){
	int arr[10];
	int i;
	for(i=0;i<=9;i++){
		scanf("%d",&arr[i]);
	}
	
	for(i=3;i<=9;i++){
		arr[i-1]=arr[i];
	}
	
	for(i=5;i<=8;i++){
		arr[i-1]=arr[i];
	}
	
	for(i=0;i<=7;i++){
		printf("%d ",arr[i]);
	}
	
	printf("\n%d",arr[4]);
	return 0;
}
