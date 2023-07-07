import io
import sys
_INPUT = """\
4 4
....
....
....
....

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from sys import stdin
input=lambda :stdin.readline()[:-1]

H, W = map(int, input().split())
C = [list(input()) for _ in range(H)]

d = [(1, 0), (-1, 0), (0, 1), (0, -1)]

ans = -1
for i in range(H):
    for j in range(W):
        if C[i][j] == "#":
            continue
        sh = i
        sw = j
        def f(h, w, s, k):
            global ans, sh, sw
            s += 1 << (h * W + w)
            for dh, dw in d:
                nh = h + dh
                nw = w + dw
                if not (0 <= nh < H and 0 <= nw < W and C[nh][nw] == "."):
                    continue
                t = nh * W + nw
                if s & (1<<t):
                    if nh == sh and nw == sw and k >= 3:
                        ans = max(ans, k+1)
                    continue
                f(nh, nw, s, k+1)
            return

        f(sh, sw, 0, 0)

print(ans)