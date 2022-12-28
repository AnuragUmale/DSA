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

    for(int i = 0; i < number_of_terms; i++){
        printf("Enter the coefficient for the term %d \t", i + 1);
        scanf("%f",&coeff);

        printf("Enter the exponent for the term %d \t", i + 1);
        scanf("%d", &expo);
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

node* add_polynomials_using_linked_list(node *head_1, node *head_2){
    node *ptr_1 = head_1;
    node *ptr_2 = head_2;
    node *head = NULL;
    while(ptr_1 != NULL && ptr_2 != NULL){
        if(ptr_1->exponent == ptr_2->exponent){
            head = insert_in_linked_list(head, ptr_1->coefficient + ptr_2->coefficient, ptr_1->exponent);
            ptr_1 = ptr_1->link;
            ptr_2 = ptr_2->link;
        }
        else if(ptr_1->exponent > ptr_2->exponent){
            head = insert_in_linked_list(head,ptr_1->coefficient,ptr_1->exponent);
            ptr_1 = ptr_1->link;
        }
        else if(ptr_2->exponent > ptr_1->exponent){
            head = insert_in_linked_list(head,ptr_2->coefficient, ptr_2->exponent);
            ptr_2 = ptr_2->link;
        }
    }
    while(ptr_1 != NULL){
        head = insert_in_linked_list(head,ptr_1->coefficient,ptr_1->exponent);
        ptr_1 = ptr_1->link;
    }
    while(ptr_2 != NULL){
        head = insert_in_linked_list(head,ptr_2->coefficient,ptr_2->exponent);
        ptr_2 = ptr_2->link;
    }
    return head;
}

node *multiply_polynomials_using_linked_list(node *head_1, node *head_2){
    node *ptr_1 = head_1;
    node *ptr_2 = head_2;
    node *head_3 = NULL;

    if(head_1 == NULL && head_2 == NULL){
        printf("Zero Polynomial\n");
        return NULL;
    }
    while(ptr_1 != NULL){
        while(ptr_2 != NULL){
            head_3 = insert_in_linked_list(head_3,ptr_1->coefficient * ptr_2->coefficient, ptr_1->exponent + ptr_2->exponent);
            ptr_2 = ptr_2->link;
        }
        ptr_1 = ptr_1->link;
        ptr_2 = head_2;
    }
    node *temp = NULL;
    node *ptr_3 = head_3;
    while(ptr_3->link != NULL){
        if(ptr_3->exponent == ptr_3->link->exponent){
            ptr_3->coefficient = ptr_3->coefficient + ptr_3->link->coefficient;
            temp = ptr_3->link;
            ptr_3->link = ptr_3->link->link;
            free(temp);
            temp = NULL;
        }
        else{
            ptr_3 = ptr_3->link;
        }
    }
    return head_3;
}





int main(){
    printf("Enter the first polynomial\n");
    node *head_1 = create_the_polynomial(head_1);
    printf("Enter the Second polynomial\n");
    node *head_2 = create_the_polynomial(head_2);
    system("clear");
    node *head_3 = multiply_polynomials_using_linked_list(head_1,head_2);
    print_polynomial(head_1);
    print_polynomial(head_2);
    printf("Polynomials after multiplication\n");
    print_polynomial(head_3);

    return 0;
}