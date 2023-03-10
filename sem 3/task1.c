#include <stdio.h>

int main (void) {
    char line_i[256];
    int count_i = 0;
    char line_o[256];
    int count_o = 0;

    while (1) {
        char temp = getchar();
        if (temp != '\n') {
            line_i[count_i] = temp;
            count_i++;
        } else {
            line_i[count_i] = '\0';
            break;
        }
    }

    for (int i=0; i < count_i-2; ++i) {
        if (line_i[i+1] == '-') {
            /* ???????????
            if (i-1 >= 0) {
                if (line_i[i-1] == '-') {
                    i++;
                }
            }
            ???????????? */ 
            if (line_i[i] < line_i[i+2]) {
                for (char j = line_i[i]; j <= line_i[i+2]; ++j) {
                    line_o[count_o] = j;
                    count_o++;
                }
                i += 2;
            } else if (line_i[i] > line_i[i+2]) {
                for (char j = line_i[i]; j >= line_i[i+2]; --j) {
                    line_o[count_o] = j;
                    count_o++;
                }
                i += 2;
            } else {
                line_o[count_o] = line_i[i];
                count_o++;
                i += 2;
            }
        } else {
            line_o[count_o] = line_i[i];
            count_o++;
        }
    }

    line_o[count_o] = line_i[count_i-2];
    line_o[count_o+1] = line_i[count_i-1];
    line_o[count_o+2] = '\0';
    printf("%s\n", line_o);
    return 0;
}