#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct node node;

struct node{
    char data;
    node *link;
};

node *top = NULL;

node* create_new_node_for_singly_linked_list_stack(char data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

void push(char data){
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

char popped_value(){
    if(top == NULL){
        printf("The Stack is alredy empty!\n");
        return -1;
    }
    node *temp = top;
    char value = temp->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return value;
}

bool is_empty(){
    if(top == NULL){
        return true;
    }
    else{
        return false;
    }
}

int matched_char(char a, char b){
    if(a == '[' && b == ']'){
        return 1;
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '(' && b == ')'){
        return 1;
    }
    if(a == '<' && b == '>'){
        return 1;
    }
    return 0;
}

int check_balanced(char *s){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<'){
            push(s[i]);
        }
        if(s[i] == ')' || s[i] == ']' || s[i] == '}' || s[i] == '>'){
            if(is_empty()){
                printf("Right Brackets are more than left brackets\n");
                return 0;
            }
            else{
                char temp = popped_value();
                if(!matched_char(temp,s[i])){
                    printf("Mismatched Brackets\n");
                    return 0;
                }
            }
        }
    }
    if(is_empty()){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char expr[MAX];
    printf("Enter the algebraic expression: \t");
    gets(expr);
    if(check_balanced(expr)){
        printf("Expression is Valid\n");
    }else{
        printf("Expression is Invalid\n");
    }
    return 0;
}