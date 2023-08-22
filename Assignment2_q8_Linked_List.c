#include <stdio.h>
#include <stdlib.h>

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

typedef struct queue{
	node* front; 
	node* rear;
	int count;
}queue;

queue* create(){
	queue* q=(queue*)malloc(sizeof(queue));
	q->front=NULL;
	q->rear=NULL;
	q->count=0;
	return q;
}


void print_ll(queue* q){
	node* ptr=q->front;
	int i;
	if(q->count==0){
		printf("Empty Queue\n");
	}
	else{	
		for(i=0;i<q->count;i++){
			printf("%d ",ptr->val);
			ptr=ptr->next;
		}
    }
	printf("\n");
}


void isEmpty(queue* q){
	if(q->front==NULL){
		printf("UnderFlow\n");
	}else{
		printf("Not Underflow\n");
	}
}


void enqueue(queue* q,int n){
	if(q->rear==NULL){
		node* x=Node(n);
		q->front=x;
		q->rear=x;
		q->rear->next=q->front;	
		q->count++;
		printf("Enqueue Successful\n");	
	}else{
		if(q->count<100){
			q->rear->next=Node(n);
			q->rear=q->rear->next;
			q->rear->next=q->front;
			q->count++;
			printf("Enqueue Successful\n");
	    }else{
	    	printf("Overflow\n");
	    }
    }
}

void dequeue(queue* q){
	if(q->count==0){
		printf("Underflow\n");
	}
	else if(q->front==q->rear){
		q->front==NULL;
		q->rear==NULL;
		q->count--;
		printf("Dequeue Successful\n");
	}
	else{		
		q->front=q->front->next;
		q->rear->next=q->front;
		q->count--;
		printf("Dequeue Successful\n");
    }
}


void Overflow(queue* q){
	if(q->count>=100){
		printf("Overflow\n");
	}else{
		printf("Not Overflow\n");
	}
}

int main(){
	printf("Queue Created\n\n");
	queue* q=create();
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
				enqueue(q,val);
				break;
				
			case 2:
				dequeue(q);
				break;
				
			case 3:
				printf("Number of elements:%d\n",q->count);
				break;
				
			case 4:
				isEmpty(q);
				break;
				
			case 5:
				Overflow(q);
				break;
				
			case 6:
				print_ll(q);
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
