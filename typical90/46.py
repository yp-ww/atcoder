import io
import sys
_INPUT = """\
3
10 13 93
5 27 35
55 28 52

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

dp = [[0] * 46 for _ in range(3)]

for i in range(N):
    a = A[i]
    a %= 46
    dp[0][a] += 1

for i in range(N):
    b = B[i]
    b %= 46
    for j in range(46):
        dp[1][(j+b)%46] += dp[0][j]

for i in range(N):
    c = C[i]
    c %= 46
    for j in range(46):
        dp[2][(j+c)%46] += dp[1][j]

print(dp[2][0])


        