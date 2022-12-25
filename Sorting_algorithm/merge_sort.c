#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int *right, int *left, int left_count, int right_count){
    int i = 0, j = 0, k = 0;
    while(i < left_count && j < right_count){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < left_count){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < right_count){
        arr[k] = right[j];
        j++;
        k++;
    }
}

// n will be calculated in main function int mid = sizeof(arr)/sizeof(arr[0]); where arr is array not pointer

void merge_sort(int *arr, int n){
    int mid, left_count, right_count;
    if(n < 2){
        return;
    }
    mid = n / 2;
    left_count = mid;
    right_count = n - mid;
    int *left = (int*)malloc(left_count * sizeof(int));
    int *right = (int*)malloc(right_count * sizeof(right_count));
    for(int i = 0; i < mid; i++){
        left[i] = arr[i];
    }
    for(int i = mid; i < n; i++){
        right[i - mid] = arr[i];
    }
    merge_sort(left,left_count);
    merge_sort(right, right_count);
    merge(arr,left,right,left_count,right_count);
    free(left);
    free(right);
}