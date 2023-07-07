import io
import sys
_INPUT = """\
2
-1 2
1 1

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from sys import stdin
input=lambda :stdin.readline()[:-1]

N = int(input())

X = []
Y = []
for _ in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)

X.sort()
Y.sort()

xcum = [0]
ycum = [0]
for i in range(N):
    xcum.append(xcum[-1] + X[i])
    ycum.append(ycum[-1] + Y[i])

cx = 10 ** 30
cy = 10 ** 30
for i in range(N):
    x = X[i]
    y = Y[i]
    
    tempx = x * i - xcum[i] + (xcum[N] - xcum[i]) - x * (N-i) 
    tempy = y * i - ycum[i] + (ycum[N] - ycum[i]) - y * (N-i)
    cx = min(cx, tempx)
    cy = min(cy, tempy)

print(cx + cy)

