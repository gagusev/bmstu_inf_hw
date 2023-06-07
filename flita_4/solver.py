def bfs(graph, node, wanted, visited, found):
    queue = []

    visited[node] = True
    queue.append(node)

    while queue:
        m = queue.pop(0)

        if len(graph[m]) == wanted:
            found.append(m)

        for neighbour in graph[m]:
            if not visited[neighbour]:
                visited[neighbour] = True
                queue.append(neighbour)

def solve(graph, wanted):
    visited = [False]*len(graph)
    found = []
    
    bfs(graph, 0, wanted, visited, found)

    while True:
        for node in visited:
            if node is False:
                bfs(graph, node, wanted, visited, found)
                break
        break

    return found