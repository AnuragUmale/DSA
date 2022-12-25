#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n){
    for(int i = 1; i <= n - 1; i++){
        int value = arr[i];
        int hole = i;
        while(hole > 0 && arr[hole - 1] > value){
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
}