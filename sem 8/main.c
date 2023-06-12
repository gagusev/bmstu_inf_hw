#include <stdio.h>
#include <stdlib.h>

#include "task1.h"
#include "task2.h"

#define BUFF 128

void task1(void)
{
    char t[BUFF];
    char s[BUFF];
    printf("s: ");
    scanf("%s", s);
    printf("t: ");
    scanf("%s", t);
    if (strEndCheck(s, t) == 1)
    {
        printf("'%s' ends with '%s'\n", s, t);
    }
    else
    {
        printf("'%s' doesn't end with '%s'\n", s, t);
    }
}

void task2(void)
{
    int arr_len;
    scanf("%d\n", &arr_len);
    char *arr_of_lines[arr_len];
    IndexSizeBundle arr_to_sort[arr_len];

    for (int i = 0; i < arr_len; ++i)
    {

        char c;
        int line_size = 0;
        char *line = NULL;

        while ((c = getchar()) != '\n')
        {

            ++line_size;
            line = realloc(line, line_size * sizeof(char));
            line[line_size - 1] = c;
        }

        ++line_size;
        line = realloc(line, line_size * sizeof(char));
        line[line_size - 1] = '\0';
        arr_of_lines[i] = line;
        IndexSizeBundle bundle = {.index = i, .size = line_size};
        arr_to_sort[i] = bundle;
    }

    quickSort(arr_to_sort, 0, arr_len - 1);

    puts("Sorted lines:");
    for (int i = 0; i < arr_len; ++i)
    {
        printf("%s\n", arr_of_lines[arr_to_sort[i].index]);
    }
}

int main(void)
{
    puts("");
    puts("ENTER THE TASK NUMBER:");
    puts("1 - STREND TEST;");
    puts("2 - SORT STRINGS BY LENGTH");
    char c;
    scanf("%c", &c);
    puts("");
    if (c == '1')
    {
        task1();
    }
    else if (c == '2')
    {
        task2();
    }
    else
    {
        puts("ERROR: THERE'S NO SUCH TASK");
        return 1;
    }
    return 0;
}