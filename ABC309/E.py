import io
import sys
_INPUT = """\
7 3
1 2 1 3 3 3
1 1
1 2
4 3

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

N, M = map(int, input().split())
P = list(map(int, input().split()))

G = [list() for _ in range(N+1)]

node = [0] * (N+1)
d = [0] * (N+1)
d[1] = 1
for i in range(2, N+1):
    p = P[i-2]
    G[p].append(i)
    d[i] = d[p] + 1

from collections import defaultdict

dis = defaultdict(list)
for i in range(1, N+1):
    dis[d[i]].append(i)

for _ in range(M):
    x, y = map(int, input().split())
    node[x] = max(node[x], y+1)

for key in dis:
    for now in dis[key]:
        for nex in G[now]:
            node[nex] = max(node[nex], node[now]-1)

cnt = 0
for i in range(1, N+1):
    if node[i]:
        cnt += 1
print(cnt)

