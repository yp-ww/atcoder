import io
import sys
_INPUT = """\
2
0 0 1 1
1 1 2 2

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())

MAX = 1100
G = [[0] * MAX for _ in range(MAX)]

for _ in range(N):
    lx, ly, rx, ry = map(int, input().split())
    G[lx][ly] += 1
    G[rx][ry] += 1
    G[lx][ry] -= 1
    G[rx][ly] -= 1

cum = [[0] * (MAX + 1) for _ in range(MAX + 1)]

for i in range(1, MAX + 1):
    for j in range(1, MAX + 1):
        cum[i][j] = cum[i-1][j] + cum[i][j-1] - cum[i-1][j-1] + G[i-1][j-1]

ans = [0] * (N+1)
for i in range(1, MAX + 1):
    for j in range(1, MAX + 1):
        ans[cum[i][j]] += 1

for i in range(1, N+1):
    print(ans[i])