#include <stdio.h>
#include <stdlib.h>


struct Node{
    char data;
    struct Node *left;
    struct Node *right;
};


void deapth_first_preorder_traversal(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%c ",root->data);
    deapth_first_preorder_traversal(root->left);
    deapth_first_preorder_traversal(root->right);
}

struct Node *newNode(char x)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->right = NULL;
    temp1->left = NULL;
    return temp1;
}

struct Node *Insert(struct Node *root, char x)
{
    if (root == NULL)
    {
        root = newNode(x);
    }
    else if (x <= root->data)
    {
        root->left = Insert(root->left, x);
    }

    else
    {
        root->right = Insert(root->right, x);
    }
    return root;
}


int main(){
    /*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	struct Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');
    printf("Preorder: ");
    deapth_first_preorder_traversal(root);
    printf("\n");

    return 0;
}