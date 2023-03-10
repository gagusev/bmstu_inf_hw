#include <stdio.h>

int main (void) {

    int ticks[10] = {};

    while (1) {
        char temp = getchar();
        if (temp != '\n') {
            if (temp >= '0' && temp <= '9') {
                ticks[temp-48] += 1;
            }
        } else {
            break;
        }
    }

    printf("\nHorizontal histogram:\n\n");

    for (int i=0; i <= 9; ++i) {
        char row[32];
        int row_c = 0;
        for (int j=0; j < ticks[i]; ++j) {
            row[row_c] = '#';
            row_c++;
        }
        row[row_c] = '\0';
        printf("%d: %s\n", i, row);
    }

    printf("\nVertical histogram:\n\n");

    int max;
    for (int i=0; i <= 9; ++i) {
        int t = ticks[i];
        if (t > max) {
            max = t;
        }
    }
    for (int i = max; i >= 1; --i) {
        char row[32];
        int row_c = 0;
        for (int j=0; j <= 9; ++j)  {
            if (ticks[j] >= i) {
                row[row_c] = '#';
            } else {
                row[row_c] = ' ';
            }
            row_c++;
            row[row_c] = ' ';
            row_c++;
        }
        row[row_c] = '\0';
        printf("%s\n", row);
    }
    printf("0 1 2 3 4 5 6 7 8 9\n\n");
    
    return 0;
}