import io
import sys
_INPUT = """\
4 1 3

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, A, B = map(int, input().split())
MOD = 10 ** 9 + 7


def cmb(n, k, MOD):
    res = 1
    for i in range(n-k+1, n+1):
        res *= i
        res %= MOD

    for i in range(1, k+1):
        res *= pow(i, MOD-2, MOD)
        res %= MOD
    return res

a = cmb(N, A, MOD)
b = cmb(N, B, MOD)

ans = pow(2, N, MOD) - 1
ans -= a
ans -= b
ans %= MOD
print(ans)
