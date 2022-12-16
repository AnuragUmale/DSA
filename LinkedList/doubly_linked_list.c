#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

Node *head;
Node* create_new_node(int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void add_to_empty_list(int data){
    Node *temp = create_new_node(data);
    head = temp;
}

void insert_at_the_beginning_doubly_linked_list(int data){
    Node *new_node = create_new_node(data);
    if(head == NULL){
        head = new_node;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void insert_at_the_end_of_doubly_linked_list(int data){
    Node *new_node = create_new_node(data);
    Node *traverser = head;
    while(traverser->next != NULL){
        traverser = traverser->next;
    }
    traverser->next = new_node;
    new_node->prev = traverser;
}

void printing_the_elements_in_forward_for_doubly_linked_list(){
    Node *temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void printing_the_elements_in_reverse_for_doubly_linked_list(){
    Node *temp = head;
    if(temp == NULL){
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}