import io
import sys
_INPUT = """\
10 2


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, K = map(int, input().split())
MOD = 10 ** 9 + 7

ans = K
if N == 1:
    print(ans)
    exit(0)

if N >= 2:
    ans *= (K-1)
    ans %= MOD
    ans *= pow(K-2, N-2, MOD)
    ans %= MOD

print(ans)