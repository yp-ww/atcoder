import io
import sys
_INPUT = """\
5 7
skunsek
nukesnu
ukeseku
nsnnesn
uekukku

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from collections import deque
H, W = map(int, input().split())

S = [list(input()) for _ in range(H)]

if S[0][0] != "s":
    print("No")
    exit(0)

q = deque()
q.append((0, 0))

arr = ["s", "n", "u", "k", "e"]

v = [[-1] * W for _ in range(H)]
v[0][0] = 0
while q:
    now_h, now_w = q.popleft()
    for dh, dw in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
        nex_h = now_h + dh
        nex_w = now_w + dw
        if not ((0 <= nex_h < H) and (0 <= nex_w < W)):
            continue
        if v[nex_h][nex_w] != -1:
            continue
        ns = S[nex_h][nex_w]
        if ns != arr[(v[now_h][now_w]+1)%5]:
            continue
        v[nex_h][nex_w] = (v[now_h][now_w]+1)%5
        q.append((nex_h, nex_w))

if v[H-1][W-1] == -1:
    print("No")
else:
    print("Yes")


