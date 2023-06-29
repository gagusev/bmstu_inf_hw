#include "hash_table.h"

#define MAX_WORD 128

int main(void) {
    HashTable *table = init_table(SIZE);

    puts("Menu:\n1 - add\n2 - remove\n3 - list\n4 - quit");

    while (1) 
    {
        int c;
        scanf("%d", &c);
        if (c == 1)
        {
            char key[MAX_WORD];
            char value[MAX_WORD];
            scanf("%s %s", key, value);
            hash_insert(table, key, value);
        }
        else if (c == 2)
        {
            char key[MAX_WORD];
            scanf("%s", key);
            hash_remove(table, key);
        }
        else if (c == 3)
        {
            hash_list(table);
        }
        else if (c == 4)
        {
            break;
        }
        else
        {
            puts("ERROR: No such instruction!");
        }
    }
    return 0;
}