#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE 1024

typedef struct Item
{
    char* key;
    char* value;
} Item;

typedef struct HashTable
{
    Item** items;
    int size;
    int count;
} HashTable;

Item* init_item(char* key, char* value)
{
    Item* item = (Item*) malloc(sizeof(Item));
    item->key = (char*) malloc(strlen(key) + 1);
    item->value = (char*) malloc(strlen(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}

void free_item(Item* item)
{
    free(item->key);
    free(item->value);
    free(item);
}

HashTable* init_table(int size)
{
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Item**) calloc(table->size, sizeof(Item*));

    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;

    return table;
}

unsigned long hashify(char* str)
{
    unsigned long i = 0;

    for (int j = 0; j < strlen(str); ++j)
        i += str[j];

    return i % SIZE;
}

void hash_insert(HashTable *table, char *key, char *value)
{
    Item *item = init_item(key, value);
    int index = hashify(key);
    Item *current_item = table->items[index];

    if (current_item == NULL)
    {
        table->items[index] = item;
        table->count++;
    }
    else
    {
        strcpy(table->items[index]->value, value);
    }
}

void hash_remove(HashTable *table, char *key)
{
    int index = hashify(key);
    Item *item = table->items[index];

    if (item != NULL)
    {
        table->items[index] = NULL;
        free_item(item);
        table->count--;
        return;
    }
}

void hash_list(HashTable *table)
{
    for (int i = 0; i < table->size; i++)
    {
        if (table->items[i])
        {
            printf("%s %s\n", table->items[i]->key, table->items[i]->value);
        }
    }
}