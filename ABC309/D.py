import io
import sys
_INPUT = """\
3 4 6
1 2
2 3
4 5
4 6
1 3
6 7

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

N1, N2, M = map(int, input().split())

G = [list() for _ in range(N1+N2)]

for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

from collections import deque

q = deque()
q.append(0)
v = [-1] * (N1+N2)
v[0] = 0
while q:
    now = q.popleft()
    for nex in G[now]:
        if v[nex] != -1:
            continue
        v[nex] = v[now] + 1
        q.append(nex)

d1 = max(v)

q = deque()
q.append(N1+N2-1)
v = [-1] * (N1+N2)
v[N1+N2-1] = 0
while q:
    now = q.popleft()
    for nex in G[now]:
        if v[nex] != -1:
            continue
        v[nex] = v[now] + 1
        q.append(nex)

d2 = max(v)

print(d1+d2+1)

