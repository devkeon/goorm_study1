def solution(n, s, a, b, fares):
    INF = float("inf")
    answer = INF
    graph = [[INF for _ in range(n + 1)] for i in range(n + 1)]
    for i in range(n + 1):
        graph[i][i] = 0

    for u, v, c in fares:
        graph[u][v] = c
        graph[v][u] = c

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    for k in range(1, n + 1):
        answer = min(answer, graph[s][k] + graph[k][a] + graph[k][b])
    return answer
