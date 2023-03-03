#include <stdio.h>
#define LIMIT 256

int main (void) {
    char output[LIMIT];
    char c;
    int w_count, o_count = 0;
    while(1) {
        c = getchar();
        if (c == '\n') {
            break;
        } else {
            if (c != '\t' && c != ' ') {
                output[o_count] = c;
                o_count++;
                w_count++;
            } else {
                if (w_count != 0) {
                    output[o_count] = '\n';
                    o_count++;
                }
                w_count = 0;
            }
        }
    }
    output[o_count] = '\0';
    printf(output);
    return 0;
}