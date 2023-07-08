import io
import sys
_INPUT = """\
4
0101
1101
1111
0000

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

N = int(input())
A = [list(input()) for _ in range(N)]

B = [[0] * N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if not (i == 0 or j == 0 or i == N-1 or j == N-1):
            B[i][j] = A[i][j]
            continue
        if i == 0:
            if j == 0:
                B[i][j] = A[i+1][j]
            else:
                B[i][j] = A[i][j-1]
        elif i == N-1:
            if j == N-1:
                B[i][j] = A[i-1][j]
            else:
                B[i][j] = A[i][j+1]
        elif j == 0:
            B[i][j] = A[i+1][j]

        elif j == N-1:
            B[i][j] = A[i-1][j]


for i in range(N):
    temp = ""
    for b in B[i]:
        temp += str(b)
    print(temp)