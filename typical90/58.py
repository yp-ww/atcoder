import io
import sys
_INPUT = """\
99999 1000000000000000000

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, K = map(int, input().split())

MAX = 100000
dp = [[0] * MAX for _ in range(70)]

def f(x):
    res = 0
    for j in range(5):
        res += (x//(10**j)) % 10
    return (res + x) % (10**5)

for i in range(MAX):
    dp[0][i] = f(i)

for i in range(1, 70):
    for j in range(MAX):
        dp[i][j] = dp[i-1][dp[i-1][j]]

now = N
for k in range(70):
    if (1<<k) & K:
        now = dp[k][now]
print(now)
