import random

def generateGraph(vertex_num):
    graph = {}
    for i in range(0, vertex_num):
        adjacency = []
        for j in range(0, vertex_num):
            if (i != j and random.randrange(0, 1000) < 100):
                adjacency.append(j)
        graph[i] = adjacency
    return graph