import io
import sys
_INPUT = """\
10 5
9 7 1 5 2 2 5 5 7 6
7 2 7 8 2
3 2 4 1 2


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import heapq
import bisect
N, M = map(int, input().split())
P = list(map(int, input().split()))
L = list(map(int, input().split()))
D = list(map(int, input().split()))

P.sort()
G = [list() for _ in range(N)]

for i in range(M):
    l = L[i]
    d = D[i]
    idx = bisect.bisect_left(P, l)
    if idx == N:
        continue
    else:
        G[idx].append(-d)

h = []
ans = 0
for i in range(N):
    ans += P[i]
    for g in G[i]:
        heapq.heappush(h, g)
    if h:
        d = heapq.heappop(h)
        ans += d

print(ans)