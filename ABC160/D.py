import io
import sys
_INPUT = """\
7 3 7

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from collections import deque
N, X, Y = map(int, input().split())

G = [list() for _ in range(N)]
for i in range(N-1):
    G[i].append(i+1)
    G[i+1].append(i)

G[X-1].append(Y-1)
G[Y-1].append(X-1)

ans = [0] * N

for i in range(N):
    q = deque()
    q.append(i)
    v = [-1] * N
    v[i] = 0
    while q:
        now = q.popleft()
        for nex in G[now]:
            if v[nex] != -1:
                continue
            v[nex] = v[now] + 1
            ans[v[nex]] += 1
            q.append(nex)

for k in range(1, N):
    print(ans[k]//2)


