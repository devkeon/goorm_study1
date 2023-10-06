import sys
import heapq
read = sys.stdin.readline

t = int(read())
INF = float('inf')
for _ in range(t):
    n, d, c = map(int, read().split())
    graph = [[] for k in range(n + 1)]
    dist = [INF for k in range(n + 1)]
    for i in range(d):
        a, b, s = map(int, read().split())
        graph[b].append([a, s])
    heap = []
    dist[c] = 0
    heapq.heappush(heap, [c, 0])
    while heap:
        node, cost = heapq.heappop(heap)
        if dist[node] < cost:
            continue
        for nxt, costt in graph[node]:
            distance = costt + cost
            if dist[nxt] > distance:
                dist[nxt] = distance
                heapq.heappush(heap, [nxt, distance])
    ans, cnt = 0, 0
    for i in range(n + 1):
        if dist[i] != INF:
            ans = max(ans, dist[i])
            cnt += 1
    print(cnt, ans)
