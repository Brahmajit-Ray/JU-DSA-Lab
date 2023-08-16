#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int val;
	struct node* next;
}node;

node* Node(int n){
	node* head=(node*)malloc(sizeof(node));
	head->val=n;
	head->next=NULL;
	return head;
}

bool isEmpty(node* top){
	if(top==NULL){
		return true;
	}
	
	return false;
}

bool isFull(node* top){
	node* p=(node*)malloc(sizeof(node));
	if(p==NULL){
		return true;
	}
	
	return false;
}

node* push(node* top,int m){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }else{
        node* n=(node*)malloc(sizeof(node));
        n->val=m;
        n->next=top;
        return n;
    }
}

node* pop(node* top){
	node* tmp;
    if(isEmpty(top)){
        printf("Stack Underflow\n");
    }else{
        int x=top->val;
        tmp=top->next;
        printf("%d\n",x);
		return tmp; 
    }
}

void print_ll(node* head){
	while (head!=NULL){
		printf("%d ",head->val);
		head=head->next;
	}
	printf("\n");
}

int main(){
	int arr[6]={1,2,3,4,5,6},i,var,flag=1,val;
	node* top=Node(arr[0]),*ptr=top,*tmp;
	for(i=1;i<6;i++){
		ptr->next=Node(arr[i]);
		ptr=ptr->next;
	}
	
	printf("Stack already present:\n");
	print_ll(top);
	printf("\n");
	
	printf("Enter 1 for Checking if stack Empty:\n");
	printf("Enter 2 for Checking if stack is full:\n");
	printf("Enter 3 for Popping:\n");
	printf("Enter 4 for Pushing:\n");
		
	while(flag){
		
		printf("Enter function:\n");
		scanf("%d",&var);		

		switch(var){		
			
			case 1:
				if (isEmpty(top)){
					printf("The stack is empty\n");
				}else{
					printf("Not empty\n");
				}
				break;
				
			case 2:
				if (isFull(top)){
					printf("The stack is full\n");
				}else{
					printf("Not full\n");
				}
				break;
				
			case 3:
				tmp=pop(top);
				printf("The stack now is:\n");
				top=tmp;
				print_ll(top);
				break;
				
			case 4:
				printf("Enter value to the pushed:\n");
				scanf("%d",&val);
				tmp=push(top,val);
				top=tmp;
				printf("The stack now is:\n");
				print_ll(top);
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




