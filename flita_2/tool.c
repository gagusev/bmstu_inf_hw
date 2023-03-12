#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 32
#define MAX_GRAPH_NAME 64
#define MAX_VERTEX_NAME 16
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
    puts("2. The first line must contain GRAPH NAME and NUMBER OF VERTICES separated by spaces;");
    puts("3. The second line must contain NAME OF EACH VERTEX separated by spaces;");
    puts("4. All the other lines are reserved for ADJACENCY MATRIX, elements separated by spaces;\n");
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

    fprintf(fp, "digraph {\nlabel=\"%s\"\n", graph_name);

    for (int i = 0; i < vertexNum(graph); i++)
    {
        struct Vertex *ptr = graph->head[i];
        while (ptr != NULL)
        {
            fprintf(fp, "%s -> %s\n", ptr->name, graph->head[ptr->dest]->name);
            ptr = ptr->next;
        }
    }

    fprintf(fp, "}");

    fclose(fp);
}

struct Graph *loadGraph(char file_name[], char graph_name_out[])
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

    getline(&line, &len, fp);
    int ptr, counter = 0;
    char graph_name[MAX_GRAPH_NAME];
    while (1)
    {
        char sym = line[ptr++];
        if (sym == ' ')
        {
            break;
        }
        else
        {
            graph_name[counter++] = sym;
        }
    }
    graph_name[counter] = '\0';
    strcpy(graph_name_out, graph_name);
    counter = 0;

    char vertex_num_str[MAX_NUM_TO_STR];
    while (1)
    {
        char sym = line[ptr++];
        if (sym == '\n')
        {
            break;
        }
        else
        {
            vertex_num_str[counter++] = sym;
        }
    }
    vertex_num_str[counter] = '\0';
    int vertex_num = atoi(vertex_num_str);

    printf("\nGRAPH NAME: %s, NUMBER OF VERTICES: %d;\n", graph_name, vertex_num);

    getline(&line, &len, fp);
    char vetrex_names[MAX_VERTICES][MAX_VERTEX_NAME];

    ptr = 0;
    for (int i = 0; i < vertex_num; ++i)
    {
        counter = 0;
        char vertex_name[MAX_VERTEX_NAME];
        while (1)
        {
            char sym = line[ptr++];
            if (sym == ' ' || sym == '\n')
            {
                break;
            }
            else
            {
                vertex_name[counter++] = sym;
            }
        }
        vertex_name[counter] = '\0';
        strcpy(vetrex_names[i], vertex_name);
    }

    printf("NAMES OF VERTICES: ");
    for (int i = 0; i < vertex_num; ++i)
    {
        printf("%s ", vetrex_names[i]);
    }
    puts(";");

    struct Graph *graph = createGraph();

    for (int i = 0; i < vertex_num; ++i)
    {
        getline(&line, &len, fp);
        int ptr = atoi(strtok(line, " "));
        for (int j = 0; j < vertex_num; ++j)
        {
            if (ptr != 0)
            {
                struct Edge edge = {i, j};
                appendGraph(graph, edge, vetrex_names[i]);
            }
            ptr = atoi(strtok(NULL, " "));
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
        struct Graph *graph = loadGraph(argv[2], graph_name);
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