#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    char *word;
    int count;
    struct Node *left;
    struct Node *right;
} Node;

struct Node *create_node(char *word)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->word = (char *)malloc(sizeof(char) * (strlen(word) + 1));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(Node *node, char *word)
{
    if (strcmp(word, node->word) == 0)
    {
        node->count++;
        return;
    }
    if (strcmp(word, node->word) < 0)
    {
        if (node->left == NULL)
            node->left = create_node(word);
        else
            insert(node->left, word);
    }
    else
    {
        if (node->right == NULL)
            node->right = create_node(word);
        else
            insert(node->right, word);
    }
}

void print_tree(Node *node, int asc_or_desk)
{
    if (node == NULL) 
    {
        return;
    }
    if (asc_or_desk == 0)
    {
        print_tree(node->left, asc_or_desk);
        printf("%s %d\n", node->word, node->count);
        print_tree(node->right, asc_or_desk);
    }
    else
    {
        print_tree(node->right, asc_or_desk);
        printf("%s %d\n", node->word, node->count);
        print_tree(node->left, asc_or_desk);
    }
}