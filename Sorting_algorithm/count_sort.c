#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximum(int *arr, int n){
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int *arr, int n){
    int max = maximum(arr,n);
    int *count = (int*)calloc((max + 1) , sizeof(int));
    for(int i = 0; i < n; i++){
        count[arr[i]] = count[arr[i]] + 1;
    }
    int j = 0, k = 0;
    while(j <= max){
        if(count[j] > 0){
            arr[k] = j;
            count[j] = count[j] - 1;
            k = k + 1;
        }
        else{
            j = j + 1;
        }
    }
    free(count);
}   