import io
import sys
_INPUT = """\
5 5
6 17 18 29 22
39 50 25 39 25
34 34 8 25 17
28 48 25 47 42
27 47 24 32 28
4 6 3 29 28
48 50 21 48 29
44 44 19 47 28
4 49 46 29 28
4 49 45 1 1

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
B = [list(map(int, input().split())) for _ in range(H)]

C = [[0] * W for _ in range(H)]
for i in range(H):
    for j in range(W):
        C[i][j] = A[i][j] - B[i][j]

ans = 0
for i in range(H-1):
    for j in range(W-1):
        temp = C[i][j]
        C[i][j] -= temp
        C[i][j+1] -= temp
        C[i+1][j] -= temp
        C[i+1][j+1] -= temp
        ans += abs(temp)

for i in range(H):
    for j in range(W):
        if C[i][j] != 0:
            print("No")
            exit(0)
print("Yes")
print(ans)