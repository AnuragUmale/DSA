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

void insert_at_the_nth_position_of_doubly_linked_list(int data, int position){
    Node *new_node_to_be_added = create_new_node(data);
    Node *temp_1 = head;
    Node *temp_2 = NULL;
    int pos = position;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    if(position == 1){
        insert_at_the_beginning_doubly_linked_list(data);
        return;
    }
    while(pos > 2){
        temp_1 = temp_1->next;
        pos--;
    }
    temp_2 = temp_1->next;
    temp_1->next = new_node_to_be_added;
    temp_2->prev = new_node_to_be_added;
    new_node_to_be_added->next = temp_2;
    new_node_to_be_added->prev = temp_1;
}

void creating_entire_doubly_linked_list(){
    int n, data;
    printf("Enter the total number of nodes for doubly linked list:\t");
    scanf("%d",&n);
    if(n <= 0){
        printf("Invalid Number for creation of doubly linked list\n");
        return;
    }
    printf("Enter the data for the node 1:\t");
    scanf("%d",&data);
    add_to_empty_list(data);
    for(int i = 1; i < n; i++){
        printf("Enter the data for the node %d:\t",i + 1);
        scanf("%d",&data);
        insert_at_the_end_of_doubly_linked_list(data);
    }
}

void deleting_first_node_of_doubly_linked_list(){
    Node *temp_1 = head;
    Node *temp_2 = NULL;
    while(temp_1->next != NULL){
        temp_1 = temp_1->next;
    }
    temp_2 = temp_1->prev;
    temp_2->next = NULL;
    free(temp_1);
    temp_1 = NULL;
}

void deleting_last_node_of_doubly_linked_list(){
    head = head->next;
    free(head->prev);
    head->prev = NULL;
}

void deleting_nth_node_of_doubly_linked_list(int position){
    Node *temp_1 = head;
    Node *temp_2 = NULL;
    if(position == 1){
        deleting_first_node_of_doubly_linked_list();
        return;
    }
    while(position > 1){
        temp_1 = temp_1->next;
        position--;
    }
    if(temp_1->next == NULL){
        deleting_last_node_of_doubly_linked_list();
    }
    else{
        temp_2 = temp_1->prev;
        temp_2->next = temp_1->next;
        temp_1->next->prev = temp_2;
        free(temp_1);
        temp_1 = NULL;
    }
}

void reversing_doubly_linked_list(){
    Node *ptr_1 = head;
    Node *ptr_2 = ptr_1->next;
    ptr_1->next = NULL;
    ptr_1->prev = ptr_2;
    while(ptr_2 != NULL){
        ptr_2->prev = ptr_2->next;
        ptr_2->next = ptr_1;
        ptr_1 = ptr_2;
        ptr_2 = ptr_2->prev;
    }
    head = ptr_1;
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