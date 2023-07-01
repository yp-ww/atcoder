import io
import sys
_INPUT = """\
5121
312000000 4123 3314
6
123
12
445
4114
42
1233


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import math
T = int(input())
L, X, Y = map(int, input().split())
Q = int(input())

for _ in range(Q):
    E = int(input())

    z = 2 * math.pi - ((E%T)/T)*math.pi*2
    a = (L/2) * math.sin(z)
    b = - (L/2) * math.cos(z)
    
    x1 = x2 = -X
    y1 = y2 = a - Y
    z1 = b + L/2
    z2 = 0
    ans = math.acos((x1*x2+y1*y2+z1*z2)/(math.sqrt(x1**2+y1**2+z1**2)*math.sqrt(x2**2+y2**2+z2**2))) * 180/math.pi

    print(ans)
