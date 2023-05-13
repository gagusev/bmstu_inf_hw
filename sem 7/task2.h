#include <stdlib.h>
#include <stdio.h>

char* readLine(void) {
    char* string = NULL;
    int size = 0;
    char c;

    while (1) {


        c = getchar();
        if (c == '\n') {
            if (size == 0) {
                continue;
            }
            break;
        }
        ++size;
        string = realloc(string, size * sizeof(char));
        string[size-1] = c;
    }
    ++size;
    string = realloc(string, size * sizeof(char));
    string[size-1] = '\0';

    return string;
}