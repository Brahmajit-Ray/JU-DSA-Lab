#include <stdio.h>

typedef struct term{
    int coeff;
    int expo;
}term;

typedef struct pol{
    term arr[10];
    int n;
}pol;


int main(){
    pol pol1,pol2;
    int i,j,m,count=0;
    printf("Enter no of terms of pol1:");
    scanf("%d",&pol1.n);
    for(i=0;i<pol1.n;i++){
        scanf("%d %d",&pol1.arr[i].coeff,&pol1.arr[i].expo);
    }
    
    printf("Enter no of terms of pol2:");
    scanf("%d",&pol2.n);
    for(i=0;i<pol2.n;i++){
        scanf("%d %d",&pol2.arr[i].coeff,&pol2.arr[i].expo);
    } 
    
    m=pol1.n * pol2.n;
    pol pol3;
    pol3.n=m;
    for(i=0;i<pol1.n;i++){
        for(j=0;j<pol2.n;j++){
            pol3.arr[count].coeff=pol1.arr[i].coeff*pol2.arr[j].coeff;
            pol3.arr[count].expo=pol1.arr[i].expo+pol2.arr[j].expo;
            count++;
        }
    }
   
    printf("\n");
    for(i=0;i<m-1;i++){
        for(j=i+1;j<m;j++){
            if(pol3.arr[i].expo==pol3.arr[j].expo){
                pol3.arr[i].coeff+=pol3.arr[j].coeff;
                pol3.arr[j].coeff=0;
                pol3.arr[j].expo=0;
            }
        }
    }
    
    printf("\n\n");
    for(i=0;i<m;i++){
        if(pol3.arr[i].coeff!=0){
        printf("%dx^%d+ ",pol3.arr[i].coeff,pol3.arr[i].expo);
        }
    }
    
    return 0;
}

