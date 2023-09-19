#include <stdio.h>
#include <stdlib.h>

typedef struct btnode{
	int data;
	struct btnode* left;
	struct btnode* right;
}btnode;

btnode* Node(int val){
	btnode* head=(btnode*)malloc(sizeof(btnode));
	head->data=val;
	head->left=NULL;
	head->right=NULL;
	return head;
}



btnode* insertBST(btnode* root,int val){
	if(root==NULL){
		return Node(val);
	}
	
	if(val<root->data){
		root->left=insertBST(root->left,val);
    }
    else if(val>root->data){
    	root->right=insertBST(root->right,val);
	}
	else{
		printf("Error");
	}
	return root;
		
}




btnode* searchBST(btnode* root,int key){
	if(root==NULL){
		printf("\nKey not in tree\n");
		return NULL;
	}
	
	if(root->data==key){
		printf("\nKey in tree\n");
		return root;
	}
	
	if(root->data>key){
		return searchBST(root->left,key);
	}
	
	if(root->data<key){
		return searchBST(root->right,key);
	}
}



btnode* inorderPrec(btnode* root,int key){
	if(root==NULL){
		//printf("No inorder predecessor\n");
		return NULL;
	}
	
	if(root->data==key){
		if(root->left!=NULL){
			btnode* temp=root->left;
			while(temp->right){
				temp=temp->right;
			}
			return temp;
		}
	}
	
	else if(root->data>key){
		btnode* temp;
		temp=inorderPrec(root->left,key);
	}
	else{
		btnode* temp;
		temp=inorderPrec(root->right,key);
	}
}

btnode* findMinimum(btnode* root){
    while (root->left)
        root = root->left;
    return root;
}


btnode* inorderSucc(btnode* root,int key){
	if(root==NULL){
		//printf("No inorder successor\n");
		return NULL;
	}
	btnode* succ = NULL;
    while (root != NULL){
        if (root->data==key && root->right != NULL)
            return findMinimum(root->right);
        else if (key < root->data){
            succ = root;
            root = root->left;
        }
        else if (key> root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}


btnode* inorderSuccDel(btnode* root){
	btnode* curr=root;
	while(curr && curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}



btnode* deleteBST(btnode* root,int key){
	if(root==NULL){
		return root;
	}
	if(key<root->data){
		root->left=deleteBST(root->left,key);
	}
	
	else if(key>root->data){
		root->right=deleteBST(root->right,key);
	}
	
	else{
		
		if(root->left==NULL){
			btnode* temp=root->right;
			free(root);
			return temp;
		}
		
		else if(root->right==NULL){
			btnode* temp=root->left;
			free(root);
			return temp;
		}
		
		btnode* temp=inorderSuccDel(root->right);
		root->data=temp->data;
		root->right=deleteBST(root->right,temp->data);
		
	}
	
	return root;	
	
}



void inorderPrint(btnode* root){
	if(root){
		inorderPrint(root->left);
		printf("%d ",root->data);
		inorderPrint(root->right);
	}
}



int main(){
	
	int dec,flag=1,val;
	btnode* root=NULL;
	btnode* dummy;
	
	printf("Enter 1 for creating a BST:\n");
	printf("Enter 2 for searching for a key:\n");
	printf("Enter 3 for inorder predecessor:\n");
	printf("Enter 4 for inorder successor:\n");
	printf("Enter 5 for inserting node:\n");
	printf("Enter 6 for deleting node:\n");
	printf("Enter 7 for inorder traversal:\n");
	
	while(flag){
		
		printf("\nEnter function:");
		scanf("%d",&dec);
		
		switch(dec){
			case 1:
				printf("Enter the number of elements: ");
                int i,n;
                scanf("%d", &n);
                printf("Enter %d elements:\n", n);
                for ( i = 0; i < n; i++) {
                    int element;
                    scanf("%d", &element);
                    root = insertBST(root, element);
                }
                break;
				
			case 2:
				printf("Enter value to be searched for:\n");
				scanf("%d",&val);
				searchBST(root,val);
				break;
				
			case 3:
				printf("Enter value for inorder predecessor:\n");
				scanf("%d",&val);
				dummy=inorderPrec(root,val);
				if(dummy!=NULL){
					printf("\nPredecessor:%d",dummy->data);
				}else{
					printf("No predecessor\n");
				}
				break;
				
			case 4:
				printf("Enter value for inorder successor:\n");
				scanf("%d",&val);
				dummy=inorderSucc(root,val);
				if(dummy!=NULL){
					printf("\nSuccessor:%d",dummy->data);
				}else{
					printf("No Successor\n");
				}
				break;
				
			case 5:
				printf("Enter value to be inserted:\n");
				scanf("%d",&val);
				root=insertBST(root,val);
				printf("\nInserted\n");
				break;
				
			case 6:
				printf("Enter value to be deleted:\n");
				scanf("%d",&val);
				root=deleteBST(root,val);
				if(root!=NULL){
					printf("\nDeleted\n");
				}
				else{
					printf("Node not found\n");
				}
				break;
				
			case 7:
				inorderPrint(root);
				break;
				
			default:
				printf("Wrong Command\n");
				break;
				
		}
		
		printf("\n");
		printf("\nPress 1 to continue,0 to terminate:");
		scanf("%d",&flag);
			
	}
	return 0;
	
}
