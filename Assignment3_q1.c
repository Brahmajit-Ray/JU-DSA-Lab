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

void inorder(btnode* root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void preorder(btnode* root){
	if(root){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(btnode* root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

int main(){
	btnode* root=Node(1);
	root->left=Node(2);
	root->right=Node(3);
	root->left->left=Node(4);
	root->left->right=Node(5);
	root->right->right=Node(6);
	
	printf("Inorder\n");
	inorder(root);
	printf("\n");
	
	printf("Preorder\n");
	preorder(root);
	printf("\n");
	
	printf("Postorder\n");
	postorder(root);
	printf("\n");
}
