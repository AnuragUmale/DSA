#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int data;
    struct Node* link;
};

Node *head;

void insert_in_the_beginnig(int value_to_be_inserted){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = value_to_be_inserted;
    temp->link = head;
    head = temp;
}

void insert_at_end(Node *head,int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    Node *ptr = head;
    temp->data = data;
    temp->link = NULL;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void insert_at_nth_position(Node *head,int data,int position){
    Node *temp_1 = (Node*)malloc(sizeof(Node));
    temp_1->data = data;
    temp_1->link = NULL;
    if(position == 1){
        temp_1->link = head;
        head = temp_1;
        return;
    }
    Node *temp_2 = head;
    for(int i = 0; i < position - 2; i++){
        temp_2 = temp_2->link;
    }
    temp_1->link = temp_2->link;
    temp_2->link = temp_1;
}

void delete_first_node(Node *head){
    if(head == NULL){
        printf("The Linked List Is Alredy Empty!\n");
        return;
    }
    Node *temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
}

void delete_last_node(Node *head){
    if(head == NULL){
        printf("The Linked List Is Alredy Empty!\n");
        return;
    }
    else if(head->link == NULL){
        free(head);
        head = NULL;
    }
    else{
        Node *temp = head;
        while(temp->link->link != NULL){
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

int count_of_node(Node *head){
    if(head == NULL){
        printf("The Linked List is Empty!!\n");
    }
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        count += 1;
        temp = temp->link;
    }
    return count;
}

void print_the_linked_list(Node *head){
    if(head == NULL){
        printf("The Linked List is Empty!!\n");
    }
    Node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}
