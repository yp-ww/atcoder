import io
import sys
_INPUT = """\
2 2 4

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
A, B, C = map(int, input().split())

import math
x = math.gcd(A, B)
x = math.gcd(x, C)

print((A+B+C-3*x)//x)