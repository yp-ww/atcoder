import io
import sys
_INPUT = """\
1 3 3
AAaA

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

x,y,z=map(int,input().split())
s=input()
INF = 10000000000000
n = len(s)
dp = [[INF]*(n+1) for _ in range(2)]

dp[0][0] = 0
dp[1][0] = z
for i in range(n):
    if s[i]=='a':
        dp[0][i+1] = min(dp[0][i]+x, dp[1][i]+x+z)
        dp[1][i+1] = min(dp[1][i]+y, dp[0][i]+y+z)
    else:
        dp[0][i+1] = min(dp[0][i]+y, dp[1][i]+y+z)
        dp[1][i+1] = min(dp[1][i]+x, dp[0][i]+x+z)     

# print(dp)
print(min(dp[0][n], dp[1][n]))

