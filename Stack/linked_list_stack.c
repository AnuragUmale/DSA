#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node{
    int data;
    Node *link;
};

Node *top = NULL;

Node* create_new_node_for_singly_linked_list_stack(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

void insert_in_the_beginnig_for_singly_linked_list_stack(int data){
    Node *new_node = create_new_node_for_singly_linked_list_stack(data);
    if(new_node == NULL){
        printf("Error: Stack Overflow\n");
        return;
    }
    new_node->link = top;
    top = new_node;
}

void delete_first_node_for_singly_linked_list_stack(){
    if(top == NULL){
        printf("The Stack is alredy empty!\n");
        return;
    }
    Node *temp = top;
    top = top->link;
    free(temp);
    temp = NULL;
}

int returning_value_and_delete_first_node_for_singly_linked_list_stack(){
    if(top == NULL){
        printf("The Stack is alredy empty!\n");
        return -1;
    }
    Node *temp = top;
    int value = temp->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return value;
}

bool is_linked_list_stack_empty(){
    if(top == NULL){
        return true;
    }
    else{
        return false;
    }
}

int top_value_from_linked_list_stack(){
    if(is_linked_list_stack_empty()){
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int count_of_node_for_singly_linked_list_stack(){
    if(top == NULL){
        printf("The Stack is Empty!!\n");
        return -1;
    }
    int count = 0;
    Node *temp = top;
    while(temp != NULL){
        count += 1;
        temp = temp->link;
    }
    return count;
}

void print_the_linked_list_for_singly_linked_list_stack(){
    if(top == NULL){
        printf("The Stack is Empty!!\n");
        return;
    }
    Node *temp = top;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}