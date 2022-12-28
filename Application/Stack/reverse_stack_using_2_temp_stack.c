#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int data;
    node *link;
};


node* create_new_node_for_singly_linked_list_stack(int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

void push(node **top, int data){
    node *new_node = create_new_node_for_singly_linked_list_stack(data);
    if(new_node == NULL){
        printf("Error: Stack Overflow\n");
        return ;
    }
    new_node->link = (*top);
    (*top) = new_node;
    
}

void pop(node **top){
    if(top == NULL){
        printf("The Stack is alredy empty!\n");
        return;
    }
    node *temp = *top;
    (*top) = (*top)->link;
    free(temp);
    temp = NULL;
}

int popped_value(node **top){
    if(top == NULL){
        printf("The Stack is alredy empty!\n");
        return -1;
    }
    node *temp = (*top);
    int value = temp->data;
    (*top) = (*top)->link;
    free(temp);
    temp = NULL;
    return value; 
}

node *revrse_stack(node **top_1, int number){
    node *top_2 = NULL, *top_3 = NULL;
    for(int i = 0; i < number; i++){
        push(&top_2,popped_value(top_1));
    }
    for(int i = 0; i < number; i++){
        push(&top_3,popped_value(&top_2));
    }
    for(int i = 0; i < number; i++){
        push(top_1,popped_value(&top_3));
    }
    return *top_1;
}


void print_stack(node **top){
    node *temp = *top;
    if(*top == NULL){
        printf("Stack is empty\n");
        return;
    }
    while(temp){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


int main(){
    node *top_1 = NULL;
    int number,data;
    printf("Enter the total numbers you want to reverse:\t");
    scanf("%d", &number);

    for(int i = 0; i < number; i++){
        printf("Enter the number %d:\t" ,i + 1);
        scanf("%d",&data);
        push(&top_1, data);
    }
    print_stack(&top_1);

    top_1 = revrse_stack(&top_1,number);    
    print_stack(&top_1);
    return 0;
}