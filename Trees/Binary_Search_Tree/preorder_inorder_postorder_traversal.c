#include <stdio.h>
#include <stdlib.h>


struct Node{
    char data;
    struct Node *left;
    struct Node *right;
};

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

void depth_first_preorder_traversal(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%c ",root->data);
    depth_first_preorder_traversal(root->left);
    depth_first_preorder_traversal(root->right);
}


// The below function will give the data in sorted order
void depth_first_inorder_traversal(struct Node *root){
    if(root == NULL){
        return;
    }
    depth_first_inorder_traversal(root->left);
    printf("%c ",root->data);
    depth_first_inorder_traversal(root->right);
}

void depth_first_postorder_traversal(struct Node* root){
    if(root == NULL){
        return;
    }
    depth_first_postorder_traversal(root->left);
    depth_first_postorder_traversal(root->right);
    printf("%c ",root->data);

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
    depth_first_preorder_traversal(root);
    printf("\n");
    printf("Inorder: ");
    depth_first_inorder_traversal(root);
    printf("\n");
    printf("Postorder: ");
    depth_first_postorder_traversal(root);
    printf("\n");

    return 0;
}