#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct queue{
	int arr[50];
	int front,rear;
}queue;

queue* create(){
	queue* q=(queue*)malloc(sizeof(queue));
	q->front=-1;
	q->rear=-1;
	
	return q;
}

void enqueue(queue* q,int val){
	if(q->front==-1 && q->rear==-1){
		q->front=0;
		q->rear=0;
		q->arr[q->rear]=val;
	}
	else if((q->rear+1)%MAX_SIZE==q->front){
		printf("Queue Full\n");
	}else{
		q->rear++;
		q->arr[(q->rear)%MAX_SIZE]=val;
		printf("Operation Successful\n");
	}
}

void dequeue(queue* q){
	if((q->front==-1)&&(q->rear==-1)){
		printf("Empty Queue\n");
	}
	else if(q->rear==q->front){
		printf("%d",q->arr[q->front]);
		q->front=-1;
		q->rear=-1;
		printf("\nDequeue Successful\n");
	}
	
	else{
		printf("%d",q->arr[q->front+1]);
		q->front=(q->front+1)%MAX_SIZE;
		printf("Dequeue Successful\n");
	}
}

void Printq(queue* q){
	int i;
	if(q->front==-1 && q->rear==-1){
		printf("Empty Queue\n");
	}else{
	printf("The queue is:");
	for(i=q->front;i<=q->rear;i++){
		printf("%d ",q->arr[i]);
	    }
    }
	printf("\n");
}

void num(queue* q){
	if(q->front==-1 && q->rear==-1){
		printf("Number of elements:%d\n",(q->rear)-(q->front));
	}
	else{
	printf("Number of elements:%d\n",(q->rear)-(q->front)+1);
    }
}

void CheckUnderflow(queue* q){
	if(q->rear==-1){
		printf("Underflow\n");
	}else{
		printf("Not Underflowing\n");
	}
}

void CheckOverflow(queue* q){
	if(q->rear==MAX_SIZE-1){
		printf("Overflow\n");
	}else{
		printf("Not Overflowing\n");
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
				Printq(q);
				break;
				
			case 2:
				dequeue(q);
				Printq(q);
				break;
				
			case 3:
				num(q);
				break;
				
			case 4:
				CheckUnderflow(q);
				break;
				
			case 5:
				CheckOverflow(q);
				break;
				
			case 6:
				Printq(q);
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
