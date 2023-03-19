#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 32
#define MAX_EDGES 64
#define MAX_GRAPH_NAME 64
#define MAX_NUM_TO_STR 8
#define MAX_CMD_STRING 64

void throwHelp()
{
    puts("\nSO HERE IS THE USER MANUAL!\n");
    puts("THERE ARE ONLY TWO COMMANDS RIGHT THERE:\n");
    puts("[LOAD / -l / -L] <filename> –– will load graph from a file and visualize it;");
    puts("[HELP / -h / -H] –– will display this message once more;\n");
    puts("FILE YOU'RE LOADING FROM MUST SATISFY FEW PROPERTIES:\n");
    puts("1. It must be plain text file (.txt), no other format is supported;");
    puts("2. Note that the file's name then will be used as GRAPH'S NAME;");
    puts("3. Only Incidence matrices are accaptable as input;");
    puts("4. All the lines must contain the same amount of [0/1] separated by spaces;\n");
    puts("THE OUTPUT IS: <GRAPH_NAME>.dot and <GRAPH_NAME>.png;\n");
}

struct Graph
{
    struct Vertex *head[MAX_VERTICES];
};

struct Vertex
{
    int dest;
    char name[16];
    struct Vertex *next;
};

struct Edge
{
    int src, dest;
};

struct Graph *createGraph()
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    for (int i = 0; i < MAX_VERTICES; ++i)
    {
        graph->head[i] = NULL;
    }
    return graph;
}

void appendGraph(struct Graph *graph, struct Edge edge, char name[])
{
    struct Vertex *newVertex = (struct Vertex *)malloc(sizeof(struct Vertex));
    newVertex->dest = edge.dest;
    newVertex->next = graph->head[edge.src];
    strcpy(newVertex->name, name);
    graph->head[edge.src] = newVertex;
}

int vertexNum(struct Graph *graph)
{
    int i = 0;
    while (graph->head[i] != NULL)
    {
        i++;
    }
    return i;
}

void printGraph(struct Graph *graph)
{
    puts("\nGRAPH PREVIEW:\n");
    for (int i = 0; i < vertexNum(graph); i++)
    {
        struct Vertex *ptr = graph->head[i];

        printf("%s[%d] —> { ", ptr->name, i);
        while (ptr != NULL)
        {
            printf("%s[%d] ", graph->head[ptr->dest]->name, ptr->dest);
            ptr = ptr->next;
        }
        printf("}\n");
    }
}

void saveGraph(struct Graph *graph, char graph_name[])
{
    char file_name[MAX_GRAPH_NAME];
    sprintf(file_name, "%s.dot", graph_name);

    FILE *fp;
    fp = fopen(file_name, "w");

    fprintf(fp, "strict graph {\nlabel=\"%s\"\n", graph_name);

    for (int i = 0; i < vertexNum(graph); i++)
    {
        struct Vertex *ptr = graph->head[i];
        while (ptr != NULL)
        {
            fprintf(fp, "%s -- %s\n", ptr->name, graph->head[ptr->dest]->name);
            ptr = ptr->next;
        }
    }

    fprintf(fp, "}");

    fclose(fp);
}

struct Graph *loadGraph(char file_name[])
{
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        puts("\nERROR: File writing operation failed");
        exit(1);
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int matrix[MAX_VERTICES][MAX_EDGES];
    for (int i = 0; i < MAX_VERTICES; ++i)
    {
        for (int j = 0; j < MAX_EDGES; ++j)
        {
            matrix[i][j] = -1;
        }
    }

    int row_counter = 0;
    int num_counter = 0;
    while ((read = getline(&line, &len, fp)) != -1)
    {
        num_counter = 0;
        for (int i = 0; i < read; ++i)
        {
            if (line[i] != ' ' && line[i] != '\0')
            {
                if (line[i] == '0')
                {
                    matrix[num_counter][row_counter] = 0;
                }
                else
                {
                    matrix[num_counter][row_counter] = 1;
                }
                num_counter++;
            }
        }
        row_counter++;
    }

    struct Graph *graph = createGraph();

    for (int i = 0; i < num_counter - 1; ++i)
    {
        int a_vertex = -1;
        int b_vertex = -1;
        for (int j = 0; j < row_counter; ++j)
        {
            if (matrix[i][j] == 1)
            {
                if (a_vertex == -1)
                {
                    a_vertex = j;
                }
                else
                {
                    b_vertex = j;
                }
            }
        }
        if (a_vertex != -1)
        {
            char str_a_vertex[MAX_NUM_TO_STR];
            sprintf(str_a_vertex, "%d", a_vertex);
            if (b_vertex != -1)
            {
                char str_b_vertex[MAX_NUM_TO_STR];
                sprintf(str_b_vertex, "%d", b_vertex);
                struct Edge edge_i = {a_vertex, b_vertex};
                appendGraph(graph, edge_i, str_a_vertex);
                struct Edge edge_j = {b_vertex, a_vertex};
                appendGraph(graph, edge_j, str_b_vertex);
            }
            else
            {
                struct Edge edge = {a_vertex, a_vertex};
                appendGraph(graph, edge, str_a_vertex);
            }
        }
    }

    fclose(fp);

    return graph;
}

void visualizeGraph(char graph_name[])
{
    char call_a[MAX_CMD_STRING];
    sprintf(call_a, "dot -Tpng > %s.png %s.dot", graph_name, graph_name);
    system(call_a);
    char ans;
    printf("\nShowcase the visualization? [Y/n]: ");
    scanf("%c", &ans);
    if (ans == 'Y')
    {
        char call_b[MAX_CMD_STRING];
        sprintf(call_b, "open %s.png", graph_name);
        system(call_b);
    }
}

void path_to_name(char path[], char out_name[])
{
    int len = strlen(path);
    int start_copy = 0;
    char name[MAX_GRAPH_NAME];
    int name_len = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        if (path[i] == '/')
        {
            break;
        }
        if (start_copy)
        {
            name[name_len++] = path[i];
        }
        if (path[i] == '.')
        {
            start_copy = 1;
        }
    }
    char reverse_name[MAX_GRAPH_NAME];
    for (int i = 0; i < name_len; ++i)
    {
        reverse_name[i] = name[name_len - i - 1];
    }
    reverse_name[name_len - 1] = '\0';
    strcpy(out_name, reverse_name);
}

int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        throwHelp();
    }
    else if (!strcmp(argv[1], "HELP") || !strcmp(argv[1], "-h") || !strcmp(argv[1], "-H"))
    {
        throwHelp();
    }
    else if (argc == 3 && (!strcmp(argv[1], "LOAD") || !strcmp(argv[1], "-l") || !strcmp(argv[1], "-L")))
    {
        char graph_name[MAX_GRAPH_NAME];
        path_to_name(argv[2], graph_name);
        struct Graph *graph = loadGraph(argv[2]);
        printGraph(graph);
        saveGraph(graph, graph_name);
        visualizeGraph(graph_name);
    }
    else
    {
        puts("\nERROR: Either too many arguments provided or bad syntax");
        throwHelp();
    }

    return 0;
}