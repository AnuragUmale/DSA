/*
    1) To represent n digit number we require n nodes of singly linked list
    2) Reverse number for addition (last digit will be in last node
    so to simplyfy we will reverse the singly linked list).
    3) add the numbers and store the resultant in singly linked list
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node node;

struct node{
    int data;
    node *link;
};

node *create_node(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

node *insert_in_the_beginning(node *head, int data){
    node *new_node = create_node(data);
    new_node->link = head;
    head = new_node;
    return head;
}

node *create_linked_list_for_number(node *head,int number){
    while(number != 0){
        head = insert_in_the_beginning(head,number % 10);
        number = number / 10;
    }
    return head;
}

node *reverse_linked_list_using_iterative_method_for_singly_linked_list(node* head){
    if(head == NULL){
        return head;
    }
    node *curr, *next;
    curr = head->link;
    next= head->link;
    head->link = NULL;
    while(next != NULL){
        curr = next;
        next = next->link;
        curr->link = head;
        head = curr;
    }
    return head;
}

node *add_the_numbers(node *head_1, node *head_2){
    if(head_1->data == 0){
        return head_2;
    }
    if(head_2->data == 0){
        return head_1;
    }
    node *ptr_1 = head_1;
    node *ptr_2 = head_2;
    node *head_3 = NULL;
    int carry = 0, sum = 0;
    while(ptr_1 || ptr_2){
        sum = 0;
        if(ptr_1){
            sum += ptr_1->data;
        }
        if(ptr_2){
            sum += ptr_2->data;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        head_3 = insert_in_the_beginning(head_3,sum);
        if(ptr_1){
            ptr_1 = ptr_1->link;
        }
        if(ptr_2){
            ptr_2 = ptr_2->link;
        }
    }
    if(carry){
        head_3 = insert_in_the_beginning(head_3,carry);
    }
    return head_3;
}

void print_the_number_in_linked_list(node *head){
    node *temp = head;
    if(head == NULL){
        printf("No Number \n");
    }
    else{
        while(temp->link != NULL){
            printf("%d -> ",temp->data);
            temp = temp->link;
        }
        printf("%d",temp->data);
    }
    printf("\n");
}


int main(){
    int number_1,number_2;
    node *head_1 = NULL, *head_2 = NULL,*head_3 = NULL;

    printf("Enter the first numbrer \t");
    scanf("%d",&number_1);
    head_1 = create_linked_list_for_number(head_1,number_1);
    printf("Printing the first Number before reversing\n");
    print_the_number_in_linked_list(head_1);
    head_1 = reverse_linked_list_using_iterative_method_for_singly_linked_list(head_1);
    printf("Printing the first Number after reversing\n");
    print_the_number_in_linked_list(head_1);

    printf("Enter the second numbrer \t");
    scanf("%d",&number_2);
    head_2 = create_linked_list_for_number(head_2,number_2);
    printf("Printing the second Number before reversing\n");
    print_the_number_in_linked_list(head_2);
    head_2 = reverse_linked_list_using_iterative_method_for_singly_linked_list(head_2);
    printf("Printing the second Number after reversing\n");
    print_the_number_in_linked_list(head_2);

    printf("Sum of the numbers\n");
    head_3 = add_the_numbers(head_1,head_2);
    print_the_number_in_linked_list(head_3);
    return 0;
}