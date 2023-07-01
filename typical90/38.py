import io
import sys
_INPUT = """\
4 6

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
A, B = map(int, input().split())

def gcd(x, y):
    if x > y:
        x, y = y, x
    
    z = y % x
    if z == 0:
        return x
    
    else:
        return gcd(z, x)

g = B // gcd(A, B)
if A * g > 10 ** 18:
    print("Large")
else:
    print(A * g)