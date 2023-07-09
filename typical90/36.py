import io
import sys
_INPUT = """\
3 3
-1 2
1 1
-2 -3
1
2
3

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

N, Q = map(int, input().split())
XY = []
A = []
B = []

for _ in range(N):
    x, y = map(int, input().split())
    XY.append((x, y))
    A.append(x-y)
    B.append(x+y)

A.sort()
B.sort()

for _ in range(Q):
    q = int(input())
    q -= 1
    x, y = XY[q]
    a = x - y
    b = x + y
    da0 = a - A[0]
    da1 = A[N-1] - a
    db0 = b - B[0]
    db1 = B[N-1] - b
    ans = max(da0, da1, db0, db1)
    print(ans)

