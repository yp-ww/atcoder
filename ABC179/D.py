import io
import sys
_INPUT = """\
5 2
1 1
3 4

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, K = map(int, input().split())
MOD = 998244353

LR = []
for _ in range(K):
    l, r = map(int, input().split())
    LR.append((l, r))

dp = [0] * (N+1)
dp[1] = 1

cum = [0]

for i in range(2, N+1):
    cum.append((cum[-1] + dp[i-1]) % MOD)

    for l, r in LR:
        if i - l <= 0:
            continue
        ll = max(i - r, 1)
        rr = i - l
        dp[i] += cum[rr] - cum[ll-1]
        dp[i] %= MOD

print(dp[N])