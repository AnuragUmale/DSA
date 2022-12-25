#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n){
    for(int k = 1; k <= n -1; k++){
        int flag = 0;
        for(int i = 0; i <= n - k - 1;i++){
            if(arr[i] > arr[i + 1]){
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}