#include <stdio.h>
#include <stdlib.h>

typedef struct node_circular_single node_circular_single;
typedef struct node_circular_double node_circular_double;

struct node_circular_single{
    int data;
    node_circular_single *next;
};

struct node_circular_double{
    int data;
    node_circular_double *next;
    node_circular_double *prev;
};

node_circular_single *tail_for_circular_singly_linked_list; // Easy to add nodes
node_circular_double *tail_for_circular_doubly_linked_list; // Easy to add nodes

node_circular_single *circular_singly_linked_list(int data){
    node_circular_single *new_node_singly_linked_list = (node_circular_single*)malloc(sizeof(node_circular_single));
    new_node_singly_linked_list->data = data;
    new_node_singly_linked_list->next = new_node_singly_linked_list;
    return new_node_singly_linked_list;
}

void add_to_the_empty_circular_singly_linked_list(int data){
    node_circular_single *temp = (node_circular_single*)malloc(sizeof(node_circular_single));
    temp->data = data;
    temp->next = temp;
    tail_for_circular_singly_linked_list = temp;
}

void add_node_at_the_begginnig_of_circular_singly_linked_list(int data){
    node_circular_single *new_node = (node_circular_single*)malloc(sizeof(node_circular_single));
    new_node->data = data;
    new_node->next = tail_for_circular_singly_linked_list->next;
    tail_for_circular_singly_linked_list->next = new_node;
}

void add_node_at_the_end_of_circular_singly_linked_list(int data){
    node_circular_single *new_node = (node_circular_single*)malloc(sizeof(node_circular_single));
    new_node->data = data;
    new_node->next = NULL;
    new_node->next = tail_for_circular_singly_linked_list->next;
    tail_for_circular_singly_linked_list->next = new_node;
    tail_for_circular_singly_linked_list = tail_for_circular_singly_linked_list->next;
}

void add_node_at_the_nth_position_of_circular_singly_linked_list(int data, int position){
    node_circular_single *new_node = (node_circular_single*)malloc(sizeof(node_circular_single));
    new_node->data = data;
    new_node->next = NULL;
    node_circular_single *ptr = tail_for_circular_singly_linked_list->next;
    while(position > 2){
        ptr = ptr->next;
        position--;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    if(ptr == tail_for_circular_singly_linked_list){
        tail_for_circular_singly_linked_list = tail_for_circular_singly_linked_list->next;
    }  
}

void creating_entire_circular_singly_linked_list(){
    int number_of_nodes, data;
    printf("Enter the total number of nodes for doubly linked list:\t");
    scanf("%d",&number_of_nodes);
    if(number_of_nodes <= 0){
        printf("Invalid Number for creation of doubly linked list\n");
        return;
    }
    printf("\n");
    printf("Enter the data for the node 1:\t");
    scanf("%d",&data);
    add_to_the_empty_circular_singly_linked_list(data);
    for(int i = 1; i < number_of_nodes; i++){
        printf("Enter the data for the node %d:\t",i + 1);
        scanf("%d",&data);
        add_node_at_the_end_of_circular_singly_linked_list(data);
        printf("\n");
    }
}

void delete_first_node_circular_singly_linked_list(){
    if(tail_for_circular_singly_linked_list == NULL){
        return;
    }
    if(tail_for_circular_singly_linked_list->next == tail_for_circular_singly_linked_list){
        free(tail_for_circular_singly_linked_list);
        tail_for_circular_singly_linked_list = NULL;
        return;
    }
    node_circular_single *temp = tail_for_circular_singly_linked_list->next;
    tail_for_circular_singly_linked_list->next = temp->next;
    free(temp);
    temp = NULL;
}

void delete_last_node_circular_singly_linked_list(){
    if(tail_for_circular_singly_linked_list == NULL){
        return;
    }
    if(tail_for_circular_singly_linked_list->next == tail_for_circular_singly_linked_list){
        free(tail_for_circular_singly_linked_list);
        tail_for_circular_singly_linked_list = NULL;
        return;
    }
    node_circular_single *temp = tail_for_circular_singly_linked_list->next;
    while(temp->next != tail_for_circular_singly_linked_list){
        temp = temp->next;
    }
    temp->next = tail_for_circular_singly_linked_list->next;
    free(tail_for_circular_singly_linked_list);
    tail_for_circular_singly_linked_list = temp;
}

void delete_nt_node_circular_singly_linked_list(int position){
    if(tail_for_circular_singly_linked_list == NULL){
        return;
    }
    if(tail_for_circular_singly_linked_list->next == tail_for_circular_singly_linked_list){
        free(tail_for_circular_singly_linked_list);
        tail_for_circular_singly_linked_list = NULL;
        return;
    }
    node_circular_single *temp_1 = tail_for_circular_singly_linked_list->next;
    while(position > 2){
        temp_1 = temp_1->next;
        position--;
    }
    node_circular_single *temp_2 = temp_1->next;
    temp_1->next = temp_2->next;
    if(temp_2 == tail_for_circular_singly_linked_list){
        tail_for_circular_singly_linked_list = temp_1;
    }
    free(temp_2);
    temp_2 = NULL;
}

void print_circular_singly_linked_list(){
    node_circular_single *ptr = tail_for_circular_singly_linked_list->next;
    do{
        printf("%d",ptr->data);
        ptr = ptr->next;
    }while(ptr != tail_for_circular_singly_linked_list->next);
}

node_circular_double *circular_doubly_linked_list(int data){
    node_circular_double *new_node_doubly_linked_list = (node_circular_double*)malloc(sizeof(node_circular_double));
    new_node_doubly_linked_list->data = data;
    new_node_doubly_linked_list->next = new_node_doubly_linked_list;
    new_node_doubly_linked_list->prev = new_node_doubly_linked_list;
    return new_node_doubly_linked_list;
}