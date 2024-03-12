//Aim: This program demonstrates the use of qsort()
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

void print_arr(int *arr){
    for(int i=0; i<ARR_SIZE; i++){
        printf("\n%d", *(arr+i));
    }    
}

int compare(const void *a, const void *b){
    return *((int *)a)- *((int *)b);
}
int main(){
    int arr[ARR_SIZE] = {10,8,3,6,5,1,4,7,9,2};
    printf("\nBefore sorting: ");
    print_arr(arr);
    qsort(arr, ARR_SIZE, sizeof(int), compare);
    printf("\nAfter sorting: ");
    print_arr(arr);
}
