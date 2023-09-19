#include <stdio.h>
#include <stdlib.h>

typedef struct btnode{
	int data;
	struct btnode* left;
	struct btnode* right;
}btnode;

btnode* Node(int n){
	btnode* head=(btnode*)malloc(sizeof(btnode));
	head->data=n;
	head->left=NULL;
	head->right=NULL;
	return head;
	
}

int search(int inorder[],int start,int end,int curr){
	int i;
	for(i=start;i<=end;i++){
		if(inorder[i]==curr){
			return i;
		}
	}
	return -1;
}

btnode* buildTree(int preorder[],int inorder[],int start,int end){
	static int idx=0;
	
	if(start>end){
		return NULL;
	}
	
	int curr=preorder[idx];
	idx++;
	btnode* node=Node(curr);
	
	if(start==end){
		return node;	
	}
	
	int pos=search(inorder,start,end,curr);
	node->left=buildTree(preorder,inorder,start,pos-1);
	node->right=buildTree(preorder,inorder,pos+1,end);	
	return node;
	
}

void inorderPrint(btnode* root){
	if(root){
		inorderPrint(root->left);
		printf("%d ",root->data);
		inorderPrint(root->right);
	}
}

int main(){
	int val,i;
	
	printf("Enter number of elements:");
	scanf("%d",&val);
	
	int inorder[val];
	int preorder[val];
	
	printf("Enter Inorder:");
	for(i=0;i<val;i++){
		scanf("%d",&inorder[i]);
	}
	
	printf("Enter Preorder:");
	for(i=0;i<val;i++){
		scanf("%d",&preorder[i]);
	}
	
	btnode* root=buildTree(preorder,inorder,0,4);
	inorderPrint(root);
	
}
