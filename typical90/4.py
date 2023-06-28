import io
import sys
_INPUT = """\
4 4
3 1 4 1
5 9 2 6
5 3 5 8
9 7 9 3

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]

S = [[0] * (W+1) for _ in range(H+1)]

for i in range(1, H+1):
    for j in range(1, W+1):
        S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i-1][j-1]

ans = [[0] * W for _ in range(H)]
for i in range(H):
    for j in range(W):
        ans[i][j] += S[i+1][W] - S[i][W]
        ans[i][j] += S[H][j+1] - S[H][j]
        ans[i][j] -= A[i][j]

for a in ans:
    print(*a)