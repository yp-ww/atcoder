import io
import sys
_INPUT = """\
100 4
30 40 120
30 40 30
30 40 1500
30 40 40

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

W, N = map(int, input().split())


N0 = 2**(W).bit_length()
INF = - 2**31-1
data = [INF]*(2*N0)
# a_k の値を x に更新
def update(k, x):
    k += N0-1
    data[k] = x
    while k >= 0:
        k = (k - 1) // 2
        data[k] = max(data[2*k+1], data[2*k+2])

def query(l, r):
    L = l + N0; R = r + N0
    s = INF
    while L < R:
        if R & 1:
            R -= 1
            s = max(s, data[R-1])

        if L & 1:
            s = max(s, data[L-1])
            L += 1
        L >>= 1; R >>= 1
    return s

dp = [[INF] * (W+1) for _ in range(N+1)]
dp[0][0] = 0
for i in range(1, N+1):
    for j in range(W+1):
        update(j, dp[i-1][j])

    l, r, v = map(int, input().split())
    for j in range(W+1):
        if j - l < 0:
            dp[i][j] = max(dp[i][j], dp[i-1][j])
            continue
        ll = max(0, j - r)
        rr = j - l
        vv = query(ll, rr+1)
        if vv == INF:
            dp[i][j] = max(dp[i][j], dp[i-1][j])
            continue

        dp[i][j] = max(vv + v, dp[i-1][j])

if dp[N][W] < 0:
    print(-1)
else:
    print(dp[N][W])

        
