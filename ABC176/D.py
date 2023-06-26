import io
import sys
_INPUT = """\
4 4
2 2
3 3
....
....
....
....
"""
sys.stdin = io.StringIO(_INPUT)

# Anser
H, W = map(int, input().split())
ch, cw = map(int, input().split())
gh, gw = map(int, input().split())
S = [input() for _ in range(H)]

ch -= 1
cw -= 1
gh -= 1
gw -= 1
from collections import deque
q = deque()

INF = 10 ** 30
v = [[INF] * W for _ in range(H)]
c = [[0] * W for _ in range(H)]
v[ch][cw] = 0

q.append((ch, cw))
while q:
    h, w = q.popleft()
    if h == gh and w == gw:
        break
    if c[h][w]:
        continue
    c[h][w] += 1
    for dh in [0, 1, -1, 2, -2]:
        for dw in [0, 1, -1, 2, -2]:
            nex_h = h + dh
            nex_w = w + dw
            if abs(dh) + abs(dw) == 0:
                continue
            elif abs(dh) + abs(dw) == 1:
                if 0 <= nex_h < H and 0 <= nex_w < W and S[nex_h][nex_w] == ".":
                    q.appendleft((nex_h, nex_w))
                    v[nex_h][nex_w] = min(v[nex_h][nex_w], v[h][w])
            else:
                if 0 <= nex_h < H and 0 <= nex_w < W and S[nex_h][nex_w] == ".":
                    q.append((nex_h, nex_w))
                    v[nex_h][nex_w] = min(v[nex_h][nex_w], v[h][w] + 1)

if v[gh][gw] == INF:
    print(-1)
else:
    print(v[gh][gw])
# print(v)