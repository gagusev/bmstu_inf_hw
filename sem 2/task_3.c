#include <stdio.h>
#define LIMIT 256

/* 

THROWS SEGMENTATION FAULT :(

void stop(int *o_count, int *r_count, char target, char output[]) {
    if (r_count > 2) {
        for (int i = 0; i <= *r_count; ++i) {
            output[*o_count] = target;
            o_count++;
        }
        output[*o_count] = '\n';
        o_count++;
    }
    r_count = 0;
}
*/

int main (void) {
    char output[LIMIT];
    char c, target;
    int r_count, o_count = 0;
    while(1) {
        c = getchar();
        if (c == '\n') {
            // SHOULD BE REWRITTEN
            if (r_count > 1) {
                for (int i = 0; i <= r_count; ++i) {
                    output[o_count] = target;
                    o_count++;
                }
                output[o_count] = '\n';
                o_count++;
            }
            r_count = 0;
            // END
            break;
        } else {
            if (c != '\t' && c != ' ') {
                if (target == c) {
                    r_count++;
                } else {
                    // SHOULD BE REWRITTEN
                    if (r_count > 1) {
                        for (int i = 0; i <= r_count; ++i) {
                            output[o_count] = target;
                            o_count++;
                        }
                        output[o_count] = '\n';
                        o_count++;
                    }
                    r_count = 0;
                    // END
                    target = c;
                }
            } else {
                // SHOULD BE REWRITTEN
                if (r_count > 1) {
                    for (int i = 0; i <= r_count; ++i) {
                        output[o_count] = target;
                        o_count++;
                    }
                    output[o_count] = '\n';
                    o_count++;
                }
                r_count = 0;
                // END
            }
        }
    }
    output[o_count] = '\0';
    printf(output);
    return 0;
}