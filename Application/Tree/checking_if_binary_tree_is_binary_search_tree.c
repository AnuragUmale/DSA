#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int x)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->right = NULL;
    temp1->left = NULL;
    return temp1;
}

struct Node *Insert(struct Node *root, int x)
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


/* =========================== First Approach =========================== */



bool is_sub_tree_lesser(struct Node *root, int value){
    if(root == NULL){
        return true;
    }
    if(root->data <= value
    && is_sub_tree_lesser(root->left,value)
    && is_sub_tree_lesser(root->right, value)){
        return true;
    }
    else{
        return false;   
    }
}

bool is_sub_tree_greater(struct Node *root, int value){
    if(root == NULL){
        return true;
    }
    if(root->data > value
    && is_sub_tree_greater(root->left,value)
    && is_sub_tree_greater(root->right, value)){
        return true;
    }
    else{
        return false;   
    }
}

/*
    The above two functions are expensive as we are going to each node and resding therir data
    Running time was number of nodes in trees
    Time Complexity is o(n^2)
*/

bool is_binary_search_tree_approach_1(struct Node *root){
    if(root == NULL){
        return true;
    }

    if(is_sub_tree_lesser(root->left,root->data)
    && is_sub_tree_greater(root->right,root->data)
    && is_binary_search_tree_approach_1(root->left)
    && is_binary_search_tree_approach_1(root->right)){
        return true;
    }
    else{
        return false;
    }
}



/* =========================== Second Approach =========================== */


// This is strictly for the integer data type 

// Time Complexity is o(n)

bool is_binary_search_tree_helper_function(struct Node *root,int min_value, int max_value){
    if(root == NULL){
        return true;
    }

    if(root->data > min_value
    && root->data <= max_value
    && is_binary_search_tree_helper_function(root->left, min_value, root->data)
    && is_binary_search_tree_helper_function(root->right, root->data, max_value)){
        return true;
    }
    else{
        return false;
    }
}

bool is_binary_search_tree_approach_2(struct Node *root){
    return is_binary_search_tree_helper_function(root,INT_MIN,INT_MAX);
}



/* =========================== Third Approach =========================== */

/*
    This approach is inorder traversal

    Perform inorder traversal and store the output in an array and if it is
    sorted it is binary search tree

    ---------------- This approach is in Trees Folder--------------------
*/