#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "task2.h"
#include "task3.h"
#include "task4.h"

void generateRandomArray(int arr[], int n, int max) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % max;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}

void task1() {
    int A = 0; int B = 1;
    printf("A is %d, B is %d.\n", A, B);
    SWAP(int, A, B);
    puts("Values swapped.");
    printf("Now A is %d, B is %d.\n", A, B);
    puts("");
}

void task2() {
    int size = 20; int max = 100;
    int arr[size];
    generateRandomArray(arr, size, max);
    quickSortIter(arr, size);
    int to_find = rand() % max;
    printf("Searching for %d in:\n", to_find);
    printArray(arr, size);
    puts("");
    int res = binSearch(arr, to_find, 0, size-1);
    if (res == -1) {
        puts("Element not found");
    } else {
        printf("Element found, index is %d\n", res);
    }
    puts("");
}

void task3() {
    int size = 20; int max = 100;
    int arr[size];
    generateRandomArray(arr, size, max);
    puts("Array generated is:");
    printArray(arr, size);
    puts("");
    puts("Sotring array.");
    quickSortIter(arr, size-1);
    puts("Sorted array is:");
    printArray(arr, size);
    puts(""); puts("");
}

void task4() {
    int size = 20; int max = 100;
    int arr[size];
    generateRandomArray(arr, size, max);
    puts("Array generated is:");
    printArray(arr, size);
    puts("");
    puts("Sotring array.");
    radixSort(arr, size);
    puts("Sorted array is:");
    printArray(arr, size);
    puts(""); puts("");
}

void task5() {
    int size = 10; int max = 10;
    int arr[size];
    generateRandomArray(arr, size, max);
    puts("Array generated is:");
    printArray(arr, size);
    puts("");
    puts("Sotring array.");
    countSort(arr, size, 0);
    puts("Sorted array is:");
    printArray(arr, size);
    puts(""); puts("");
}

int main(void) {
    srand(time(NULL));
    puts("");
    puts("ENTER THE TASK NUMBER:");
    puts("1 - Swap;");
    puts("2 - Binary search;");
    puts("3 - Quicksort;");
    puts("4 - Radix sort;");
    puts("5 - Counting sort;");
    puts("6 - Run full diagnostics;");
    char c = getchar();
    puts("");
    if (c == '1') {
        task1();
    } else if (c == '2') {
        task2();
    } else if (c == '3') {
        task3();
    } else if (c == '4') {
        task4();
    } else if (c == '5') {
        task5();
    } else if (c == '6') {
        task1();
        task2();
        task3();
        task4();
        task5();
    } else {
        puts("ERROR: THERE'S NO SUCH TASK");
    }
    return 0;
}