import sys

read = sys.stdin.readline

n, k, b = map(int, read().split())
broken = [1 for i in range(n)]
for _ in range(b):
    a = int(read())
    broken[a - 1] = 0

for i in range(1, n):
    broken[i] += broken[i - 1]
ans = 1000001
for i in range(n - k):
    s = broken[i + k] - broken[i]
    ans = min(ans, k - s)
print(ans)
