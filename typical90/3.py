import io
import sys
_INPUT = """\
10
1 2
1 3
2 4
4 5
4 6
3 7
7 8
8 9
8 10

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from collections import deque
N = int(input())

G = [list() for _ in range(N)]

for _ in range(N-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

q = deque()
q.append(0)

v = [-1] * N
v[0] = 0

while q:
    now = q.popleft()
    for nex in G[now]:
        if v[nex] != -1:
            continue
        v[nex] = v[now] + 1
        q.append(nex)

_max = 0
_max_pos = 0
for i in range(N):
    if v[i] > _max:
        _max_pos = i
        _max = v[i]

q = deque()
q.append(_max_pos)
v = [-1] * N
v[_max_pos] = 0

while q:
    now = q.popleft()
    for nex in G[now]:
        if v[nex] != -1:
            continue
        v[nex] = v[now] + 1
        q.append(nex)

ans = max(v) + 1

print(ans)


