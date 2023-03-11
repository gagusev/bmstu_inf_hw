#include <stdio.h>

void exclude(char line[], char to_rem[]) {
    for (int i = 0; line[i] != '\0'; ++i) {
        for (int j = 0; to_rem[j] != '\0'; ++j) {
            if (line[i] == to_rem[j]) {
                for (int k = i; line[k] != '\0'; ++k) {
                    line[k] = line[k+1];
                }
            }
        }
    }
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

    exclude(line, to_rem);
    printf("%s\n", line);

    return 0;
}