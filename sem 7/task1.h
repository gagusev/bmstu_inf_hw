#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
  
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printIntArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}

void readArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }
}