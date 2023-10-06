import math

def solution(n, times):
    mtime = max(times)
    s, e = 0, mtime * n
    while s <= e:
        mid, time = (s + e) // 2, 0
        for counsel in times:
            time += (math.floor(mid // counsel))
        if time < n:
            s = mid + 1
        elif time >= n:
            e = mid - 1
    return s
