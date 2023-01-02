#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* find_min(struct Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct Node* delete_node_in_binary_search_tree(struct Node* root, int data){
    if(root == NULL){
        return root;
    }
    else if(data < root->data){
        root->left = delete_node_in_binary_search_tree(root->left,data);
    }
    else if(data > root->data){
        root->right = delete_node_in_binary_search_tree(root->right,data);
    }
    else{
        // Case 1: No Child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        // Case 2: One Child
        else if(root->left == NULL){
            struct Node* temp_1 = root;
            root = root->right;
            free(temp_1);
            temp_1 = NULL;
        }
        else if(root->right == NULL){
            struct Node* temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }
        // Case 3: Two Children
        else{
            struct Node *temp_2 = find_min(root->right);
            root->data = temp_2->data;
            root->right = delete_node_in_binary_search_tree(root->right,temp_2->data);

        }
    }
    return root;
}

void Inorder(struct Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 
// Function to Insert Node in a Binary Search Tree
struct Node* Insert(struct Node *root,char data) {
	if(root == NULL) {
		root = (struct Node*)malloc(sizeof(struct Node));
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}


int main() {
	/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	struct Node* root = NULL;
	root = Insert(root,5); 
    root = Insert(root,10);
	root = Insert(root,3); 
    root = Insert(root,4); 
	root = Insert(root,1); 
    root = Insert(root,11);
    root = Insert(root,8);
    root = delete_node_in_binary_search_tree(root,5);
    Inorder(root);
    return 0;
}