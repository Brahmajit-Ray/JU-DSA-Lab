#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Stack{
	int arr[50];
	int top;
}Stack;

Stack* createStack(){
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    return stack;
}   


void push(Stack* stack,int op){
    stack->arr[++stack->top] = op;
}

bool Empty(Stack* stack){
    return stack->top==-1;
}

int pop(Stack* stack){
    if(!Empty(stack)){
        return stack->arr[stack->top--];
    }
}
 

int Postfix(char* exp){
    Stack* stack = createStack();
    int i;
   
    for(i=0;exp[i]!='\0';i++) {
        if (exp[i]==' ')
            continue;
 
        else if(isdigit(exp[i])) {
            int num=0;
 
            while(isdigit(exp[i])) {
                num=num*10+(int)(exp[i]-'0');
                i++;
            }
            i--;
            push(stack,num);
        }
 
        else {
            int val1=pop(stack);
            int val2=pop(stack);
 
            switch (exp[i]) {
            case '+':
                push(stack,val2+val1);
                break;
            case '-':
                push(stack,val2-val1);
                break;
            case '*':
                push(stack,val2*val1);
                break;
            case '/':
                push(stack,val2/val1);
                break;
            }
        }
    }
    return pop(stack);
}

int main(){
	
    char exp[50];
    printf("Enter experssion(Eg:100 200 + 2 / 5 * 7 +):\n");
    scanf("%[^\n]",exp);
	printf("Evaluated expression:");
    printf("%d",Postfix(exp));
    return 0;
}


















