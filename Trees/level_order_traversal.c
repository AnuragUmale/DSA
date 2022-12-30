#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000000

typedef struct binary_search_tree_node binary_search_tree_node;

struct binary_search_tree_node{
    int data;
    binary_search_tree_node* left;
    binary_search_tree_node* right;
};

binary_search_tree_node *queue[MAX_SIZE];

int front = -1, rear = -1;


void enqueue(binary_search_tree_node *address){
    if(front == -1 && rear == -1){
        front = rear = 0;
    }
    else if((rear + 1) % MAX_SIZE == front){
        printf("Memory Full\n");
        exit(1);
    }
    else{
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = address;
}

void dequeue(){
	if(front == -1 && rear == -1){
        return;
    }
	if(front == 0 && rear == 0){
		front = rear = -1;
	}
    else{
		front = (front + 1) % MAX_SIZE;
	}
}

binary_search_tree_node *first(){
    if(front == -1 && rear == -1){
        printf("The queue is already empty\n");
        return NULL;
    }
    return queue[front];
}

bool is_empty(){
    if(front == -1 && rear == -1){
        return true;
    }
    return false;
}

/*===============Binary Tree Section===============*/

binary_search_tree_node* create_node_for_binary_search_tree(int data){
    binary_search_tree_node *new_node = (binary_search_tree_node*)malloc(sizeof(binary_search_tree_node));
    if(new_node != NULL){
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

binary_search_tree_node* insert_in_binary_search_tree(binary_search_tree_node* root,int data){
    if(root == NULL){
        root = create_node_for_binary_search_tree(data);
    }
    else if(data <= root->data){
        root->left = insert_in_binary_search_tree(root->left,data);
    }
    else{
        root->right = insert_in_binary_search_tree(root->right, data);
    }
    return root;
}

void level_order_traversal_in_binary_search_tree(binary_search_tree_node *root){
    if(root == NULL){
        return;
    }
    enqueue(root);
    while(!is_empty()){
        binary_search_tree_node *current = first();
        printf("%d",current->data);
        if(current->left != NULL){
            enqueue(current->left);
        }
        if(current->right != NULL){
            enqueue(current->right);
        }
        dequeue();
    }
}


int main(){
    /*Code To Test the logic
	  Creating an example tree
	            1
			   / \
			  2   3
			 / \   \
			4   5   6
    */
	binary_search_tree_node* root = NULL;
	root = insert_in_binary_search_tree(root,1); 
    root = insert_in_binary_search_tree(root,2);
	root = insert_in_binary_search_tree(root,3); 
    root = insert_in_binary_search_tree(root,4); 
	root = insert_in_binary_search_tree(root,5); 
    root = insert_in_binary_search_tree(root,6);
    return 0;
}