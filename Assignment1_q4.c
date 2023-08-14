#include <stdio.h>
#include <math.h>

typedef struct term{
    double coeff;
    int expo;
}term;

typedef struct pol{
    term arr[10];
    int n;
}pol;


int main(){
    pol pol1;
    int i,j,val;
	float sum=0;
    printf("Enter no of terms of pol1:");
    scanf("%d",&pol1.n);
    printf("Enter coefficient,power:\n");
    
	for(i=0;i<pol1.n;i++){
        scanf("%lf %d",&pol1.arr[i].coeff,&pol1.arr[i].expo);
		}
		
	printf("Enter value:");
	scanf("%d",&val);
	
	for(i=0;i<pol1.n;i++){
		sum+=(pol1.arr[i].coeff)*pow(val,pol1.arr[i].expo);
	}
	
	printf("Evaluated value is:%lf",sum);
	
	return 0;
}
	

