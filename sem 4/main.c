#include <stdio.h>
#include <string.h>

#include "task1.h"
#include "task2.h"

int read_cmd(char str[])
{
    int counter = 0;
    while (1)
    {
        char c = getchar();
        if (c == '\n' || c == '\t' || c == ' ')
        {
            break;
        }
        else
        {
            str[counter] = c;
            counter++;
        }
    }
    return counter;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        if (!strcmp(argv[1], "task1"))
        {
            char str[16];
            int counter = read_cmd(str);
            printf("%d\n", hexstr_to_decint(str, counter));
        }
        else if (!strcmp(argv[1], "task2"))
        {
            char str[16];
            int counter = read_cmd(str);
            printf("%d\n", count_odd_bits(hexstr_to_decint(str, counter)));
        }
        else
        {
            puts("\nERROR: Unknown arguments provided\n");
        }
    }
    else
    {
        puts("\nERROR: Zero arguments provided\n");
    }
    return 0;
}