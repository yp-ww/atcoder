import io
import sys
_INPUT = """\
5 2
0 0
1 0
0 1
-1 0
0 -1

"""
sys.stdin = io.StringIO(_INPUT)

# Anser

import math
from collections import defaultdict
N, K = map(int, input().split())
if K == 1:
    print("Infinity")
    exit(0)

X = [0] * N
Y = [0] * N
for i in range(N):
    X[i], Y[i] = map(int, input().split())

d = defaultdict(int)
INF = 10 ** 30
for i in range(N):
    for j in range(i+1, N):
        x1 = X[i]
        y1 = Y[i]
        x2 = X[j]
        y2 = Y[j]
        a = x1 - x2
        b = y1 - y2
        if (a < 0):
            a *= -1
            b *= -1

        if a == 0:
            b = 1
        if b == 0:
            a = 1
        else:
            g = math.gcd(a, b)
            a //= g
            b //= g
        ac = b*x1 - a*y1
        d[(a, b, ac)] += 1

ans = 0
s = (K-1) * K // 2
for dd in d:
    if d[dd] >= s:
        ans += 1

print(ans)
# print(d)



