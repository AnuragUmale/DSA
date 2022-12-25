#include <stdio.h>
#include <stdlib.h>

void selection_soert(int arr[], int n){
    for(int i = 0; i <= n - 1; i++){
        int i_min = i;
        for(int j = i; j <= n; j++){
            if(arr[i] < arr[i_min]){
                i_min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[i_min];
        arr[i_min] = temp;
    }
}