#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct stack{
	char arr[MAX_SIZE];
	int top;
}stack;

stack* create(){
	stack* s=(stack*)malloc(sizeof(stack));
	s->top=-1;
		
	return s;
}

void push(stack* s,int val){
	if(s->top==MAX_SIZE-1){
		printf("Overflow\n");
	}
	else{
		s->top++;
		s->arr[s->top]=val;
	}
}

int pop(stack* s1){
	int x;
    if(s1->top==-1){
		printf("Underflow\n");
	}
	else{
		x=s1->arr[s1->top];
		s1->top--;
		return x;
	}
}

void enqueue(stack* s1,int val){
	push(s1,val);
}

void dequeue(stack* s1,stack* s2){
	int i,j;
	if((s1->top==-1) && (s2->top==-1)){
		printf("Underflow\n");
	}
	else{
		if((s2->top==-1)){
			j=s1->top;
			for(i=0;i<=j;i++){
				push(s2,pop(s1));
			}
	    }
		printf("%d\n",pop(s2));			

    }
}

int count(stack* s1,stack* s2){
	return s1->top+s2->top+2;
}

void print_q(stack* s1,stack* s2){
	int i;
	if(count(s1,s2)>0){
		for(i=s2->top;i>=0;i--){
			printf("%d ",s2->arr[i]);
		}
		for(i=0;i<=s1->top;i++){
			printf("%d ",s1->arr[i]);
		}
		printf("\n");
    }
	else{
    	printf("Empty Queue\n");
	}
}


void CheckUnderflow(stack* s1,stack* s2){
	if(s1->top==-1 && s2->top==-1){
		printf("Underflow\n");
	}
	else{
		printf("Not Underflow\n");
	}
}

void CheckOverflow(stack* s1){
	if(s1->top<MAX_SIZE-1){
		printf("Not Overflow\n");
	}
	else{
		printf("Overflow\n");
	}
}

int main(){
    printf("Queue Created\n\n");
	stack* s1=create();
	stack* s2=create();
	printf("Enter 1 for Enqueue\n");
	printf("Enter 2 for Dequeue\n");
	printf("Enter 3 for checking number of elements\n");
	printf("Enter 4 to check Underflow\n");
	printf("Enter 5 to check Overflow\n");
	printf("Enter 6 to view queue\n");
	int val,flag=1,var;
	
	while(flag){
		printf("\nEnter function:");
		scanf("%d",&var);		

		switch(var){		
			
			case 1:
				printf("Enter value:");
				scanf("%d",&val);
				enqueue(s1,val);
				break;
				
			case 2:
				dequeue(s1,s2);
				break;
				
			case 3:
				printf("The number of elements:%d\n",count(s1,s2));
				break;
				
			case 4:
				CheckUnderflow(s1,s2);
				break;
				
			case 5:
				CheckOverflow(s1);
				break;
				
			case 6:
				print_q(s1,s2);
				break;
				
			default:
				printf("Wrong Command\n");
				break;
		
		}
		printf("\n");
		printf("Press 1 to continue,0 to terminate:\n");
		scanf("%d",&flag);
		
	}		
	return 0;
}
	
