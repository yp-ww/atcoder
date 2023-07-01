import io
import sys
_INPUT = """\
7
19 23 51 59 91 99
15 45 56 65 69 94
7 11 16 34 59 95
27 30 40 43 83 85
19 23 25 27 45 99
27 48 52 53 60 81
21 36 49 72 82 84


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]

MOD = 10 ** 9 + 7

dp = [[0] * 6 for _ in range(N+1)]
cum = [0] * (N+1)
dp[0] = A[0]
for i in range(1, N):
    cum[i-1] = sum(dp[i-1])
    cum[i-1] %= MOD
    for j in range(6):
        dp[i][j] = cum[i-1] * A[i][j]
        dp[i][j] %= MOD

print(sum(dp[N-1])%MOD)
