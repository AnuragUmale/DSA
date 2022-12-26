#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

void circular_array_enqueue(int *arr, int n, int data){
    if((rear + 1) % n == front){
        printf("Queue is full\n");
        return;
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
    }
    else{
        rear = (rear + 1) % n;
    }
    arr[rear] = data;
}

void circular_array_dequeue(int n){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
        return;
    }
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front + 1) % n;
    }
}

int circular_arrat_front(int *arr){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        return arr[front];
    }
}