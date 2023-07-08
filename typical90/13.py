import io
import sys
_INPUT = """\
7 9
1 2 2
1 3 3
2 5 2
3 4 1
3 5 4
4 7 5
5 6 1
5 7 6
6 7 3

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

N, M = map(int, input().split())

G = [list() for _ in range(N)]
for _ in range(M):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append((b, c))
    G[b].append((a, c))

import heapq

h = []
v = [-1] * N
heapq.heappush(h, (0, 0))

while h:
    now_c, now = heapq.heappop(h)
    if v[now] != -1:
        continue
    v[now] = now_c
    for nex, c in G[now]:
        if v[nex] != -1:
            continue
        heapq.heappush(h, (now_c + c, nex))

h = []
vn = [-1] * N
heapq.heappush(h, (0, N-1))

while h:
    now_c, now = heapq.heappop(h)
    if vn[now] != -1:
        continue
    vn[now] = now_c
    for nex, c in G[now]:
        if vn[nex] != -1:
            continue
        heapq.heappush(h, (now_c + c, nex))

for k in range(N):
    print(v[k] + vn[k])