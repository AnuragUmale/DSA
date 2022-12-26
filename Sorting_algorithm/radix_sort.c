#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minimum(int *arr, int length){
    int min = INT_MAX;
    for (int i = 0; i < length; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int maximum(int *arr, int length){
    int max = INT_MIN;
    for (int i = 0; i < length; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}


int *Count_sort(int *arr, int size, int Exponent){
    int range = 10;
    int *frequency_array ;
    frequency_array = (int*)malloc(sizeof(int)* range);
    if(frequency_array == NULL){
        exit(-1);
    }
    int sum=0;
    for(int i=0; i<range; i++){
        frequency_array[ i ]=0;
    }
 
    for(int i=0;i<size;i++){
        frequency_array[ (arr[i]/Exponent)%10 ]++;
    }
 
    for(int i =0; i<range;i++){
        sum = sum + frequency_array[i];
        frequency_array[i] = sum;
    }
 
    int *new_arr;
    new_arr = (int *)malloc(sizeof(int) *size);
    if(new_arr == NULL){
        exit(-1);
    }
    else{
        int pos;
        for(int i=size-1; i>=0 ;i-- ){
            pos = frequency_array[(arr[i]/Exponent)%10]-1;
            new_arr[ pos ] = arr[ i ];
            frequency_array [(arr[i]/Exponent)%10]--;
        }
    }
    return new_arr;
}

int *Radix_sort(int *arr, int size){
    int Max_of_arr = maximum(arr, size);
    int Exponent = 1;
    int count = 0;
    while(Exponent <= Max_of_arr){
        arr = Count_sort(arr, size, Exponent);
        Exponent= Exponent* 10;
    }
    return arr;
}
