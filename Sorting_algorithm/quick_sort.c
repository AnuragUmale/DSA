#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int start, int end){
    int pivot = arr[end];
    int partition_index = start;
    for(int i = start; i < end; i++){
        if(arr[i] <= pivot){
            int temp = arr[i];
            arr[i] = arr[partition_index];
            arr[partition_index] = arr[i];
            partition_index++;
        }
    }
    int temp2 = arr[partition_index];
    arr[partition_index] = arr[end];
    arr[end] = temp2;
    return partition_index;
}

void quick_sort(int *arr, int start, int end){
    if(start >= end){
        return;
    }
    int partition_index = partition(arr,start,end);
    quick_sort(arr,start,partition_index);
    quick_sort(arr,partition_index + 1,end);
}