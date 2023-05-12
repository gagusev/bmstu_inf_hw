#include "task1.h"

int partition(int arr[], int start, int stop)
{
    int x = arr[stop];
    int i = (start - 1);
  
    for (int j = start; j <= stop - 1; j++) {
        if (arr[j] <= x) {
            i++;
            SWAP_P(int, &arr[i], &arr[j]);
        }
    }
    SWAP_P(int, &arr[i + 1], &arr[stop]);
    return (i + 1);
}


void quickSortIter(int arr[], int stop)
{   
    int start = 0; //optional

    int stack[stop - start + 1];
  
    int top = -1;
    stack[++top] = start;
    stack[++top] = stop;
  
    while (top >= 0) {

        stop = stack[top--];
        start = stack[top--];
  
        int pivot = partition(arr, start, stop);
  
        if (pivot - 1 > start) {
            stack[++top] = start;
            stack[++top] = pivot - 1;
        }

        if (pivot + 1 < stop) {
            stack[++top] = pivot + 1;
            stack[++top] = stop;
        }
    }
}