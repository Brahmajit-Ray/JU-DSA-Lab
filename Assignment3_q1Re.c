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

btnode* insert(btnode* root,int val){
    if(root == NULL){
        return Node(val);
    }
    printf("\nEnter 1 to insert in left:\n");
    printf("Enter 2 to insert in right:\n");
    int choice;
    printf("Enter choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1: 
			root->left = insert(root->left,val);
            break;
        case 2: 
			root->right = insert(root->right,val);
            break;
        default: 
			printf("Invalid choice");
        	break;
    }
    return root;
    
}

int main(){
    
    int num,val,dec,flag=1;
    btnode* root=NULL;
    
    printf("Press 1 for Inorder:\n");
    printf("Press 2 for Preorder:\n");
    printf("Press 3 for Postorder:\n");
    printf("Press 4 for Creating:\n");
    
    
    
    while(flag){
		
		printf("\nEnter function:");
		scanf("%d",&dec);
		
	    switch(dec){
	        case 1:
	            printf("Inorder:\n");
	            inorder(root);
	            printf("\n");
	            break;
	            
	        case 2:
	            printf("Preorder:\n");
	            inorder(root);
	            printf("\n");
	            break;
	            
	        case 3:
	            printf("Postorder:\n");
	            inorder(root);
	            printf("\n");
	            break;
	            
	            
	        case 4:
	        	printf("Enter value to be inserted:");
	        	scanf("%d",&val);
	        	if(root==NULL){
					root=insert(root,val);
				}
				else{
					insert(root,val);
				}
	        	printf("Inserted\n");
	        	break;
	        	
	        default:
	        	printf("Invalid Command\n");
	        	break;
	        }
	        
	    printf("\n");
		printf("\nPress 1 to continue,0 to terminate:");
		scanf("%d",&flag);
	    }
	    
	return 0;   
	
}
