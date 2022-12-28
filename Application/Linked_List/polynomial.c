#include <stdio.h>
#include <stdlib.h>


typedef struct node node;

struct node{
    float coefficient;
    int exponent;
    node *link;
};

node *create_the_node(float coeff, int expo){
    node *temp = (node *)malloc(sizeof(node));
    temp->coefficient = coeff;
    temp->exponent = expo;
    temp->link = NULL;
    return temp;
}

node *insert_in_linked_list(node *head, float coeff, int expo){
    node *new_node = create_the_node(coeff,expo);
    if(head == NULL || expo > head->exponent){
        new_node->link = head;
        head = new_node;
    }
    else{
        node *temp = head;
        while(temp->link != NULL && temp->link->exponent > expo){
            temp = temp->link;
        }
        new_node->link = temp->link;
        temp->link = new_node;
    }
    return head;
}

node* create_the_polynomial(node *head){
    int number_of_terms;
    float coeff;
    int expo;
    
    printf("Enter the number of terms: \t");
    scanf("%d", &number_of_terms);
    printf("\n");

    for(int i = 0; i < number_of_terms; i++){
        printf("Enter the coefficient for the term %d \t", i + 1);
        scanf("%f",&coeff);
        printf("\n");

        printf("Enter the exponent for the term %d \t", i + 1);
        scanf("%d", &expo);
        printf("\n");
        head = insert_in_linked_list(head,coeff,expo);

    }
    return head;
}

void print_polynomial(node *head){
    if(head == NULL){
        printf("No Polynomial\n");
        return;
    }
    else{
        node *temp = head;
        while(temp != NULL){
            printf("(%.1fx^%d)",temp->coefficient,temp->exponent);
            temp = temp->link;
            if(temp != NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }
    }
}


int main(){
    node *head = NULL;
    head = create_the_polynomial(head);
    print_polynomial(head);
    return 0;
}