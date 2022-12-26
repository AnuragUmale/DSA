#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;

struct node{
    int data;
    node *next;
};

node *head = NULL;
node *tail = NULL;

node* create_linked_list_queue_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void linked_list_enqueue(int data){
    node* temp = create_linked_list_queue_node(data);
    if(head == NULL && tail == NULL){
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
    free(temp);
    temp = NULL;
}

void linked_list_dequeue(){
    node *temp = head;
    if(head == NULL){
        return;
    }
    if(head == tail){
        head = tail = NULL;
    }
    else{
        head = head->next;
    }
    free(temp);
    temp = NULL;
}

int linked_list_front_queue(){
    if(head == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        return head->data;
    }
}

bool is_linked_list_queue_empty(){
    if(head == NULL && tail == NULL){
        return true;
    }
    else{
        return false;
    }
}