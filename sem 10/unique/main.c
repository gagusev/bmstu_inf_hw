#include "tree.h"

#define WORD_MAX_LEN 128

void execute(char *path, int option)
{
    Node *n = NULL;

    FILE *fp;
    fp = fopen(path, "r");
    if (fp == NULL)
    {
        puts("ERROR: File reading operation failed!");
        exit(1);
    }

    char word[WORD_MAX_LEN];
    while (fscanf(fp, "%s", word) != EOF) {
        if (n == NULL) {
            n = create_node(word);
        } else {
            insert(n, word);
        }
    }

    fclose(fp);

    print_tree(n, option);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        puts("ERROR: No arguments provided!");
        return 1;
    }
    else if (argc == 2)
    {
        execute(argv[1], 0);
    }
    else if (argc == 3)
    {
        puts("ERROR: Invalid syntax!");
        return 1;
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "-o") == 0)
        {
            if (strcmp(argv[2], "ASC") == 0)
            {
                execute(argv[3], 0);
            }
            else if (strcmp(argv[2], "DESC") == 0)
            {
                execute(argv[3], 1);
            }
            else
            {
                puts("ERROR: Invalid option provided!");
                return 1;
            }
        }
        else
        {
            puts("ERROR: No such option!");
            return 1;
        }
    }
    else
    {
        puts("ERROR: Too many arguments provided!");
        return 1;
    }

    return 0;
}