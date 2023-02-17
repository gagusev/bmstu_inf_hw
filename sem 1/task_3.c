#include <stdio.h>
#include <string.h>

int main() {
    int size;
    printf("Enter a desired size: ");
    scanf("%d", &size);

    char largest_num[10];
    sprintf(largest_num, "%d", size*size);
    int largest_num_len = strlen(largest_num);

    for (int i=1; i <= size; ++i) {
        for (int j=1; j <= size; ++j) {
            char num[5];
            sprintf(num, "%d", i*j);
            int len = strlen(num);
            printf(num);
            for (int p=0; p<largest_num_len-strlen(num); ++p) {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}