#include <stdio.h>
#define LIMIT 256

int main (void) {
    char output[LIMIT];
    char c;
    int count = 0;
    while(1) {
        c = getchar();
        if (c == '\n') {
            break;
        } else {
            if (c != '\t' && c != ' ') {
                output[count] = c;
                count++;
            }
        }
    }
    output[count] = '\0';
    printf(output);
    return 0;
}