#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 101

int stack_array_1 [MAX_SIZE];
int stack_array_2 [MAX_SIZE];
int top_1 = -1; // For section one
int top_2 = -1; // For section two

/*============== Section One ============== */
void push_element_in_array(int data){
    if(top_1 == MAX_SIZE - 1){
        printf("Error:\tStack Overflow\n");
        return;
    }
    top_1++;
    stack_array_1[top_1] = data;
}

void pop_element_in_array(){
    if(top_1 == -1){
        printf("Error:\tStack is empty\n");
        return;
    }
    top_1--;
}

int returning_poped_value_from_array(){
    if(top_1 == -1){
        printf("Error:\tStack is empty\n");
        return -1;
    }
    int value = stack_array_1[top_1];
    top_1--;
    return value;
}

int top_value_from_array(){
    if(top_1 == -1){
        printf("Error:\tStack is empty\n");
        return -1;
    }
    return stack_array_1[top_1];
}

bool is_array_empty(){
    if(top_1 == -1){
        return true;
    }
    else{
        return false;
    }
}

bool is_array_full(){
    if(top_1 == MAX_SIZE - 1){
        return true;
    }
    else{
        return false;
    }
}

void print_elements_in_array(){
    if(is_array_empty()){
        printf("Error:\tStack is empty\n");
        return;
    }
    printf("Stack: ");
    for(int i = 0; i<= top_1; i++){printf("%d ",stack_array_1[i]);}
    printf("\n");
}

/*============== Section Two ============== */

void push_as_top_always_index_zero(int data){
    if(top_2 == MAX_SIZE - 1){
        printf("Error:\tStack Overflow\n");
        return;
    }
    top_2++;
    for(int i = top_2; i > 0; i--){
        stack_array_2[i] = stack_array_2[i-1];
    }
    stack_array_2[0] = data;
}

void pop_as_top_always_index_zero(){
    if(top_2 == -1){
        printf("Error:\tStack is empty\n");
        return;
    }
    for(int i = 0; i < top_2; i++){
        stack_array_2[i] = stack_array_2[i+1];
    }
    top_2--;
}

int returning_poped_value_as_top_always_zero(){
    if(top_2 == -1){
        printf("Error:\tStack is empty\n");
        return -1;
    }
    int value = stack_array_2[0];
    for(int i = 0; i < top_2; i++){
        stack_array_2[i] = stack_array_2[i+1];
    }
    top_2--;
    return value;
}

int top_value_as_top_is_always_zero(){
    if(top_2 == -1){
        printf("Error:\tStack is empty\n");
        return -1;
    }
    return stack_array_2[0];
}

bool is_empty_as_top_is_always_zero(){
    if(top_2 == -1){
        return true;
    }
    else{
        return false;
    }
}

bool is_full_as_top_is_always_zero(){
    if(top_2 == MAX_SIZE - 1){
        return true;
    }
    else{
        return false;
    }
}

void print_elements_in_array_as_top_is_always_zero(){
    if(top_2 == -1){
        printf("Error:\tStack is empty\n");
        return;
    }
    printf("Stack: ");
    for(int i = 0; i<= top_2; i++){printf("%d ",stack_array_2[i]);}
    printf("\n");
}