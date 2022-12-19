#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int data;
    Node* link;
};

Node *head;

Node* create_new_node_for_singly_linked_list(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

void insert_in_the_beginnig_for_singly_linked_list(int value_to_be_inserted){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = value_to_be_inserted;
    temp->link = head;
    head = temp;
}

void insert_at_end_for_singly_linked_list(Node *head,int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    Node *ptr = head;
    temp->data = data;
    temp->link = NULL;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void insert_at_nth_position_for_singly_linked_list(int data,int position){
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

void delete_first_node_for_singly_linked_list(){
    if(head == NULL){
        printf("The Linked List Is Alredy Empty!\n");
        return;
    }
    Node *temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
}

void delete_last_node_for_singly_linked_list(){
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

void delete_node_at_nth_position_for_singly_linked_list(int position){
    Node *temp_1 = head;
    if(position == 1){
        head = temp_1->link;
        free(temp_1);
        return;
    }
    for(int i = 0; i < position - 2; i++){
        temp_1 = temp_1->link;
    }
    Node *temp_2 = temp_1->link;
    temp_1->link = temp_2->link;
    free(temp_2);
}

void delete_entire_linked_list_for_singly_linked_list(){
    Node *temp = head;
    while(temp != NULL){
        temp = temp->link;
        free(head);
        head = temp;
    }
    if(head == NULL){
        printf("Entire linked list deleted successfully!\n");
    }
    else{
        printf("Error deleting the linked list\n");
    }
}

void reverse_linked_list_using_iterative_method_for_singly_linked_list(){
    Node *curr, *next, *prev;
    curr = head;
    prev = NULL;
    while(curr != NULL){
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void reverse_linked_list_using_recurrsion_for_singly_linked_list(Node *p){
    if(p == NULL){
        head = p;
        return;
    }
    reverse_linked_list_using_recurrsion_for_singly_linked_list(p->link);
    Node *q = p->link;
    q->link = p;
    p->link = NULL;
}

int count_of_node_for_singly_linked_list(){
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

void print_the_linked_list_for_singly_linked_list(){
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

void print_forward_using_recursion_for_singly_linked_list(Node *head_1){
    if(head_1 == NULL){
        return;
    }
    printf("%d ", head_1->data);
    print_forward_using_recursion_for_singly_linked_list(head_1->link);
}

void print_reverse_using_recursion_for_singly_linked_list(Node *head_1){
    if(head_1 == NULL){
        return;
    }
    print_reverse_using_recursion_for_singly_linked_list(head_1->link);
    printf("%d ", head_1->data);
}
