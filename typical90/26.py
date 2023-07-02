import io
import sys
_INPUT = """\
6
1 3
2 4
3 5
2 5
3 6

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())
G = [list() for _ in range(N)]

for _ in range(N-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

from collections import deque
q = deque()

v = [-1] * N

q.append(0)
v[0] = 1
while q:
    now = q.popleft()
    for nex in G[now]:
        if v[nex] != -1:
            continue
        v[nex] = 0 if v[now] == 1 else 1
        q.append(nex)

cnt = 0
for i in range(N):
    if v[i] == 1:
        cnt += 1

ans = []
if cnt >= N // 2:
    for i in range(N):
        if len(ans) == N//2:
            break
        if v[i] == 1:
            ans.append(i+1)
else:
    for i in range(N):
        if len(ans) == N//2:
            break
        if v[i] == 0:
            ans.append(i+1) 

print(*ans)

