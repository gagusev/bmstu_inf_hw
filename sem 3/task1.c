#include <stdio.h>

void fill(char line_i[], char line_o[]) {
    int count_o = 0;
    char sym, last_sym;

    for (int i = 0; line_i[i] != '\0'; ++i) {
        int start = line_i[i-1];
        int dash = line_i[i];
        int stop = line_i[i+1];
        if (dash == '-') {
            if (i == 0 || stop == '\0') {
                line_o[count_o++] = '-';
            } else if (start < stop) {
                if (last_sym != start) {
                    line_o[count_o++] = start;
                }
                for (sym = start + 1; sym <= stop; ++sym) {
                    line_o[count_o++] = sym;
                }
                last_sym = sym - 1;
            }
            else {
                if (last_sym != start) {
                    line_o[count_o++] = start;
                }
                for (sym = start - 1; sym >= stop; --sym) {
                    line_o[count_o++] = sym;
                }
                last_sym = sym - 1;
            }
        }
    }
    line_o[count_o] = '\0';
}

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

    fill(line_i, line_o);
    printf("%s\n", line_o);
    
    return 0;
}