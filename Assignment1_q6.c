#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Defing a Node
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
//Getting Input
char* Input(char* ptr){
	int c,i;
	for(i=0;;i++){
		if(i==0){
			ptr=(char*)malloc(sizeof(char));
		}
		else{
			ptr=(char*)realloc(ptr,(i+1)*sizeof(char));
		}
		scanf("%c",ptr+i);
		if(ptr[i]=='\n'){
			ptr[i]='\0';
		    break;
	    }
	}
	return ptr;
}

//Creating LL
node* create_2(int* arr,int n){
	node* head=Node(arr[0]);
	int i;
	node* tmp=head;
	for(i=1;i<n;i++){
		tmp->next=Node(arr[i]);
		tmp=tmp->next;		
	}
	return head;
}

//Converting Input to LL
node* convert(char* ptr){
	char* ar;
	ar=ptr;
	int n=strlen(ar);
	int r=n%9;
	int q=n/9;
	int* arr;
	arr=(int*)malloc((q)*sizeof(int));
	int i,j,flag=0,temp;
	char ref[9];
	char res[r];
	if(r!=0){    
	    flag=1;
		for(j=0;j<r;j++){
		res[j]=ptr[j];
	    }
		arr[0]=atoi(res);
	}
	for(i=0;i<q+flag;i++){
		for(j=r+i*9;j<r+(i+1)*9;j++){
		ref[(j-r)%9]=ptr[j];
	    }
		arr[i+flag]=atoi(ref);
	}
	
	
	node* ans;
	ans=create_2(arr,q+flag);
	return ans;
}

//Printing LL

void print_ll(node* p){
	int i=0;
	while(p!=NULL){
		if(i!=0){
			printf("%09d",p->val);
			p=p->next;
			//i++;
		}else{
			printf("%d",p->val);
			p=p->next;
			i++;
		}
	}
	printf("\n");
}

//Addition Algorithm
node* add_ll(node* l1,node* l2){
	int mod=pow(10,9);
	int mod2=pow(10,8);
    node* dummy=Node(0);
    node* cur=dummy;
    int carry=0;
    int v1=0,v2=0;
    while(l1||l2||carry){
        if(l1){
            v1=(l1->val);
        }
        else{
            v1=0;
        }   
        if (l2){
            v2=(l2->val);
        }
        else{
            v2=0;
        }
        int ans=v1+v2+carry;
        carry=ans/mod;
        int rem = ans % mod;
        cur->next = Node(rem);

        cur=cur->next;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    return dummy->next;
    
}

//Reverse LL
node* reverse(node* p){
	node *l,*q,*n;
	q=p;
	l=NULL;
	n=q->next;
	while(q->next){
		q->next=l;
		l=q;
		q=n;
		n=q->next;
	}
	q->next=l;
	return q;
}

int main(){
	node *p,*q;
	node* res;
	char *head1,*head2;
	printf("Caution:Positive/Unsigned Integers only\n\n");
	
	printf("Enter num1:");
	head1=Input(head1);
	
	printf("Enter num2:");
	head2=Input(head2);
	
	printf("\n");
	
	p=convert(head1);
	print_ll(p);
	p=reverse(p);
	//print_ll(p);
	printf("+");
	
	q=convert(head2);
	print_ll(q);
	q=reverse(q);
	//print_ll(q);
	printf("=");
	
	res=add_ll(p,q);
	//print_ll(res);
	res=reverse(res);
	
	print_ll(res);
	
	return 0;
}

