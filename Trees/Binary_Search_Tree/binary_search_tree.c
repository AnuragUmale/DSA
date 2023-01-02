#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct binary_search_tree_node binary_search_tree_node;

struct binary_search_tree_node{
    int data;
    binary_search_tree_node* left;
    binary_search_tree_node* right;
};

int max(int a, int b){
    if(a > b){
        return a;
    }
    else if(a < b){
        return b;
    }
    else{
        return a;
    }
}

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

int find_min_in_binary_search_tree_iterative_method(binary_search_tree_node *root){
    if(root == NULL){
        printf("The tree is empty\n");
        return -1;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int find_max_in_binary_search_tree_iterative_method(binary_search_tree_node *root){
    if(root == NULL){
        printf("The tree is empty\n");
        return -1;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

int find_min_in_binary_search_tree_recurrsive_method(binary_search_tree_node *root){
    if(root == NULL){
        printf("The tree is empty\n");
        return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }
    return find_min_in_binary_search_tree_recurrsive_method(root->left);
}

int find_max_in_binary_search_tree_recurrsive_method(binary_search_tree_node *root){
    if(root == NULL){
        printf("The tree is empty\n");
        return -1;
    }
    else if(root->right == NULL){
        return root->data;
    }
    return find_max_in_binary_search_tree_recurrsive_method(root->right);
}

int find_height_of_binary_seach_tree(binary_search_tree_node *root){
    if(root == NULL){
        return -1;
    }
    return max(find_height_of_binary_seach_tree(root->left), find_height_of_binary_seach_tree(root->right)) + 1;
}

bool search_in_binary_search_tree(binary_search_tree_node* root, int data){
    if(root == NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(data <= root->data){
        return search_in_binary_search_tree(root->left, data);
    }
    else{
        return search_in_binary_search_tree(root->right,data);
    }
}

int main(){
    binary_search_tree_node* root = NULL;
    root = insert_in_binary_search_tree(root,12);
    root = insert_in_binary_search_tree(root,31);
    root = insert_in_binary_search_tree(root,21);
    root = insert_in_binary_search_tree(root,11);

    if(search_in_binary_search_tree(root,21)){
        printf("found 21\n");
    }
    else{
        printf("Not found 21\n");
    }

    if(search_in_binary_search_tree(root,1)){
        printf("found 1\n");
    }
    else{
        printf("Not found 1\n");
    }


    return 0;
}