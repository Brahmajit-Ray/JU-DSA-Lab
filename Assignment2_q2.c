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

node* create_ll(int n){
	int i;
	node* head=Node(1),*ptr=head;
	for(i=2;i<=n;i++){
		ptr->next=Node(i);
		ptr=ptr->next;
	}
	ptr->next=head;
	return head;
}

int Josephus(node* head,int m){
	int i;
	node* ptr=head,*p=head;
	while(p->next!=p){
		for(i=1;i<m-2;i++){
			ptr=ptr->next;
		}
		ptr->next=ptr->next->next;
		ptr=ptr->next;
		p=ptr;
	}
	return ptr->val;
	
}

int main(){
	int total,skip;
	printf("Emter total number of children,skip:");
	scanf("%d %d",&total,&skip);
	node* head=create_ll(total);
	printf("\nWinner:%d",Josephus(head,skip));
	
	return 0;
}
