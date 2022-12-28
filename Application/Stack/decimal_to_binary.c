#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int data;
    node *link;
};

node *top = NULL;

node* create_new_node_for_singly_linked_list_stack(int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

void push(int data){
    node *new_node = create_new_node_for_singly_linked_list_stack(data);
    if(new_node == NULL){
        printf("Error: Stack Overflow\n");
        return;
    }
    new_node->link = top;
    top = new_node;
}

void pop(){
    if(top == NULL){
        printf("The Stack is alredy empty!\n");
        return;
    }
    node *temp = top;
    top = top->link;
    free(temp);
    temp = NULL;
}

int popped_value(){
    if(top == NULL){
        printf("The Stack is alredy empty!\n");
        return -1;
    }
    node *temp = top;
    int value = temp->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return value;
}

void decimal_to_binary(int number){
    while(number != 0){
        push(number % 2);
        number /= 2;
    }
}

void print_binary(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    while(top != NULL){
        printf("%d",popped_value());
    }
    printf("\n");
}

int main(){
    int number;
    printf("Enter the number ");
    scanf("%d",&number);
    decimal_to_binary(number);
    print_binary();
    return 0;
}