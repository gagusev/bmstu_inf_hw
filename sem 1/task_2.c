#include <stdio.h>
#include <string.h>

void print_via_for_loop(char name[]) {
    int len = strlen(name) + 4;
    char stars[len];
    for (int i=0; i < len; ++i) {
        stars[i] = '*';
    }
    printf(stars);
    printf("\n* ");
    printf(name);
    printf(" *\n");
    printf(stars);
}

void print_via_while_loop(char name[]) {
    int len = strlen(name) + 4;
    char stars[len];
    int i = 0;
    while (len > i) {
        stars[i] = '*';
        i++;
    }
    printf(stars);
    printf("\n* ");
    printf(name);
    printf(" *\n");
    printf(stars);
}

void star_recursor(int chars_left) {
    if (chars_left > 0) {
        printf("*");
        star_recursor(chars_left-1);
    }
}

void print_via_recursion(char name[]) {
    int len = strlen(name) + 4;
    star_recursor(len);
    printf("\n* ");
    printf(name);
    printf(" *\n");
    star_recursor(len);
}

void count_and_print(char name[]) {
    int i;
    for (i=0; name[i]!='\0'; ++i);
    i+=4;
    char stars[i];
    for (int j=0; j < i; ++j) {
        stars[j] = '*';
    }
    printf(stars);
    printf("\n* ");
    printf(name);
    printf(" *\n");
    printf(stars);
}

int main() {
    char name[20] = "Grigoriy";
    printf(" #1 Printed via for-loop:\n");
    print_via_for_loop(name);
    printf("\n #2 Printed via while-loop:\n");
    print_via_while_loop(name);
    printf("\n #3 Printed via recursion:\n");
    print_via_recursion(name);
    printf("\n #4 Self-counted and printed:\n");
    count_and_print(name);
    return 0;
}