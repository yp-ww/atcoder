import io
import sys
_INPUT = """\
4 6
1 2 1
1 3 1
1 4 1
2 3 1
2 4 1
3 4 1

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import heapq
N, M = map(int, input().split())

G = [list() for _ in range(N+1)]

for i in range(M):
    a, b, c = map(int, input().split())
    G[a].append((b, c, i+1))
    G[b].append((a, c, i+1))

h = []
heapq.heappush(h, (0, 1, 0))
v = [-1] * (N+1)
ans = []
while h:
    d, now, path = heapq.heappop(h)
    if v[now] != -1:
        continue
    v[now] = d
    ans.append(path)
    for nex, cost, root in G[now]:
        if v[nex] != -1:
            continue
        heapq.heappush(h, (d+cost, nex, root))

ans = ans[1:]
print(*ans)