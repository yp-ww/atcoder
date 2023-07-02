import io
import sys
_INPUT = """\
10
attcordeer

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())
S = input()

MOD = 10 ** 9 + 7

arr = "atcoder"

dp = [[0] * (N+1) for _ in range(8)]
dp[0] = [1 for _ in range(N+1)]
for i in range(1, 8):
    s = arr[i-1]
    for j in range(1, N+1):
        dp[i][j] = dp[i][j-1]
        if s == S[j-1]:
            dp[i][j] += dp[i-1][j-1]
            dp[i][j] %= MOD

print(dp[7][N])