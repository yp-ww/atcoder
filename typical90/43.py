import io
import sys
_INPUT = """\
3 3
1 1
3 3
..#
#.#
#..

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
H, W = map(int, input().split())
rs, cs = map(int, input().split())
rt, ct = map(int, input().split())
S = [input() for _ in range(H)]
rs -= 1
cs -= 1
rt -= 1
ct -= 1

from collections import deque
INF = 10 ** 30
v = [[[INF] * 4 for _ in range(W)] for _ in range(H)]

q = deque()
for i in range(4):
    v[rs][cs][i] = 0
    q.append((rs, cs, i))

d = [(-1, 0), (1, 0), (0, -1), (0, 1)]

while q:
    h, w, i = q.popleft()
    if h == rt and w == ct:
        break
    for j in range(4):
        dh, dw = d[j]
        nh = h + dh
        nw = w + dw
        if not (0 <= nh < H and 0 <= nw < W and S[nh][nw] == "."):
            continue

        if i == j:
            if v[nh][nw][j] > v[h][w][i]:
                v[nh][nw][j] = v[h][w][i]
                q.appendleft((nh, nw, j))
        else:
            if v[nh][nw][j] > v[h][w][i] + 1:
                v[nh][nw][j] = v[h][w][i] + 1
                q.append((nh, nw, j))            

print(min(v[rt][ct]))

