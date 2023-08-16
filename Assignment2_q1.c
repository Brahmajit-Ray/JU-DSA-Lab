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

node* Insert_Node(node* head,int pos,int val){
	node* dummy=head,*tmp;
	int count=0;
	if(pos==0){
		tmp=Node(val);
		tmp->next=head;
		return tmp;
	}else{
		while(dummy && count!=pos-1){
			dummy=dummy->next;
			count++;
		}
		
		if(dummy){
			tmp=dummy->next;
			dummy->next=Node(val);
			dummy->next->next=tmp;
			return head;
		}else{
			printf("Error\n");
		}
    }
    
}

node* Delete_Node(node* head,int pos){
	node* dummy=head,*tmp;
	int count=0;
	if(pos==0){
		head=head->next;
		return head;
	}else{
		while(dummy && count!=pos-1){
			dummy=dummy->next;
			count++;
		}
		
		if(dummy->next){
			tmp=dummy->next->next;
			dummy->next=tmp;
			return head;
		}else{
			printf("Error\n");
		}
    }    
}

void Print_Reverse(node* head){
	node* p,*q;
	if(head==NULL){
		return;
	}
	p=NULL;
	while(p!=head){
		q=head;
		while(q->next!=p){
			q=q->next;
		}
		printf("%d ",q->val);
		p=q;
	}
}

void print_ll(node* head){
	while (head!=NULL){
		printf("%d ",head->val);
		head=head->next;
	}
	printf("\n");
}

node* Reverse_ll(node* head){
	node* prev=NULL,*pres=head,*future;
	future=pres->next;
	while(pres->next!=NULL){
		pres->next=prev;
		prev=pres;
		pres=future;
		future=future->next;
	}
	pres->next=prev;
	return pres;
}

int count_ll(node* head){
	int count=0;
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
}

int main(){
	int arr[6]={1,2,3,4,5,6},i,var,pos,val,flag=1;
	node* head=Node(arr[0]);
	node* ptr;
	node* dummy=head;
	for(i=1;i<6;i++){
		dummy->next=Node(arr[i]);
		dummy=dummy->next;
	}
	
	printf("Linked List already present:\n");
	print_ll(head);
	printf("\n");
	
	printf("Enter 1 for Inserting node:\n");
	printf("Enter 2 for Deleting node:\n");
	printf("Enter 3 for counting number of nodes in the list:\n");
	printf("Enter 4 for reverse printing the list:\n");
	printf("Enter 5 for reversing list:\n");
	
	while(flag){
		
		printf("Enter function:\n");
		scanf("%d",&var);		

		switch(var){		
			
			case 1:
				printf("Enter pos,val:");
				scanf("%d %d",&pos,&val);
				ptr=Insert_Node(head,pos,val);
				printf("The modified list is:\n");
				print_ll(ptr);
				head=ptr;
				break;
				
			case 2:
				printf("Enter pos:");
				scanf("%d",&pos);
				ptr=Delete_Node(head,pos);
				printf("The modified list is:\n");
				print_ll(ptr);
				head=ptr;
				break;
				
			case 3:
				printf("The total number of nodes is:%d",count_ll(head));
				break;
				
			case 4:
				Print_Reverse(head);
				break;
				
			case 5:
				ptr=Reverse_ll(head);
				printf("The modified list is:\n");
				print_ll(ptr);
				head=ptr;
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





