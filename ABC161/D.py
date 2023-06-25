import io
import sys
_INPUT = """\
100000

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
K = int(input())

dp = [[list() for _ in range(10)] for _ in range(11)]

ans = []
for j in range(10):
    dp[1][j].append(j)
    ans.append(j)

for i in range(2, 11):
    for j in range(10):
        offset = j * (10 ** (i-1))
        if j == 0:
            for nex in dp[i-1][j]:
                dp[i][j].append(nex + offset)
            for nex in dp[i-1][j+1]:
                dp[i][j].append(nex + offset)
        elif j == 9:
            for nex in dp[i-1][j-1]:
                dp[i][j].append(nex + offset)
                ans.append(nex + offset)
            for nex in dp[i-1][j]:
                dp[i][j].append(nex + offset)
                ans.append(nex + offset)
        else:
             for nex in dp[i-1][j-1]:
                dp[i][j].append(nex + offset)
                ans.append(nex + offset)
             for nex in dp[i-1][j]:
                dp[i][j].append(nex + offset)
                ans.append(nex + offset)           
             for nex in dp[i-1][j+1]:
                dp[i][j].append(nex + offset)
                ans.append(nex + offset)

print(ans[K])