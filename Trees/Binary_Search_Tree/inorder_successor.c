#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* find_min(struct Node* root){
    if(root == NULL){
        return NULL;
    }
	while(root->left != NULL){
        root = root->left;
    }
	return root;
}

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

struct Node* Find(struct Node* root, int data) {
	if(root == NULL){
        return NULL;
    }
	else if(root->data == data){
        return root;
    }
	else if(root->data < data){
        return Find(root->right,data);
    }
	else{
        return Find(root->left,data);
    }
}

struct Node* get_successor(struct Node* root, int data){

    // Search node will cost o(h) [h = height of the tree]
    // We can avoid the seach of we would have passed the node directly
    struct Node* current = Find(root, data);
    if(current == NULL){
        return NULL;
    }
    //Case 1: Node has right subtree
    if(current->right != NULL){
        return find_min(current->right);
    }
    // Case 2: Node with no right subtree
    else{
        /* If no right subtree walk to the current node and we need to find 
        deepest ancestor for which current node will be in its left subtree*/
        struct Node* successor = NULL;
        struct Node* ancestor = root;
        // Walk the tree till we reach the current node
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
        
    }

}

void Inorder(struct Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
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
    printf("Inorder: ");
    Inorder(root);
    printf("\n");
    struct Node* successor = get_successor(root,5);
    if(successor == NULL){
        printf("No successor\n");
    }
    else{
        printf("Successor = %d\n", successor->data);
    }
}