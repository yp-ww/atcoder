import io
import sys
_INPUT = """\
3 2 3
1 2 1
2 3 1
2 1 1


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import heapq
import bisect

N, M, K = map(int, input().split())
G = [list() for _ in range(N+1)]
H = [list() for _ in range(M+1)]
for i in range(M):
    a, b, c = map(int, input().split())
    G[a].append((b, c, i+1))

E = list(map(int, input().split()))
for i in range(K):
    x = E[i]
    H[x].append(i+1)

h = []
heapq.heappush(h, (0, 1, 0))
v = [-1] * (N+1)
while h:
    d, now, pos = heapq.heappop(h)
    v[now] = d
    if now == N:
        break
    for nex, cost, num in G[now]:
        if len(H[num]) == 0:
            continue
        nex_pos = bisect.bisect_left(H[num], pos)
        if nex_pos == len(H[num]):
            continue
        heapq.heappush(h, (d+cost, nex, H[num][nex_pos]))

print(v[N])


