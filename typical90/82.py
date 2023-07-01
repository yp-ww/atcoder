import io
import sys
_INPUT = """\
98 100

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
L, R = input().split()
MOD = 10 ** 9 + 7

l = len(L)
r = len(R)

L = int(L)
R = int(R)
ans = 0
for i in range(l, r+1):
    if i == l:
        _max = min(R, (10 ** l) - 1)
        ans += ((L + _max) * (_max - L + 1) // 2) * i
        ans %= MOD

    elif i == r:
        _min = (10 ** (r-1))
        ans += ((_min + R) * (R - _min + 1) // 2) * i
        ans %= MOD

    else:
        _min = 10 ** (i-1)
        _max = (10 ** i) - 1
        ans += ((_min + _max) * (_max - _min + 1) // 2) * i
        ans %= MOD
    
print(ans)