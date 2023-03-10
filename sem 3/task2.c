#include <stdio.h>

void exclude(char line[], char to_rem[], char out[]) {
    int i, j, c_out = 0;
    while (line[i] != '\0') {
        int found = 0;
        while (to_rem[j] != '\0') {
            char c = to_rem[j];
            if (line[i] == c) {
                found = 1;
                break;
            }
            j++;
        }
        if (!found) {
            out[c_out] = line[i];
            c_out++;
        }
        i++;
    }
    out[c_out] = '\0';
}

int main (void) {
    char line[256];
    int count_line = 0;
    char to_rem[256];
    int count_rem = 0;
    char out[256];

    while (1) {
        char temp = getchar();
        if (temp != '\n') {
            line[count_line] = temp;
            count_line++;
        } else {
            line[count_line] = '\0';
            break;
        }
    }
    while (1) {
        char temp = getchar();
        if (temp != '\n') {
            to_rem[count_rem] = temp;
            count_rem++;
        } else {
            to_rem[count_rem] = '\0';
            break;
        }
    }

    exclude(line, to_rem, out);
    printf("%s\n", out);

    return 0;
}