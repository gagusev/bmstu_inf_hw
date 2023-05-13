#include "task1.h"
#include "task2.h"

void task1() {
    int size;
    puts("Enter the size of an array:");
    scanf("%d", &size);

    int *nums = (int*)malloc(size * sizeof(int));
    readArray(nums, size);
    shellSort(nums, size);
    printIntArray(nums, size);
    puts(""); puts("");
    free(nums);
}

void task2() {
    puts("Enter the string:");

    char* str = readLine();

    printf("The string is: %s\n", str);
    puts("");
    free(str);
}

int main (void) {
puts("");
puts("ENTER THE TASK NUMBER:");
puts("1 - Shell Sort;");
puts("2 - String Input;");
puts("3 - Run full diagnostics;");
char c = getchar();
puts("");
if (c == '1') {
    task1();
} else if (c == '2') {
    task2();
} else if (c == '3') {
    task1();
    task2();
} else {
    puts("ERROR: THERE'S NO SUCH TASK");
}
    return 0;
}