import io
import sys
_INPUT = """\
234
"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
sys.setrecursionlimit(10**7)
K = int(input())

MOD = 10 ** 9 + 7
from functools import lru_cache

@lru_cache(maxsize=10**7)
def f(x):
    if x == 0:
        return 1
    if x == 1:
        return 1
    
    if x > 9:
        res = 0
        for i in range(1, 10):
            res += f(x-i) 
            res %= MOD
    else:
        res = 1
        for i in range(1, x):
            res += f(x-i)
            res %= MOD
    
    return res

if K % 9:
    print(0)
else:
    print(f(K))