import io
import sys
_INPUT = """\
7 3
atcoder

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

N, K = map(int, input().split())
S = input()

INF = 10 ** 30
nex = [[INF] * N for _ in range((ord("z")-ord("a")+1))]

for i in range(ord("z")-ord("a")+1):
    s = chr(ord("a") + i)
    for j in range(N):
        if s == S[j]:
            nex[i][j] = j

for i in range(ord("z")-ord("a")+1):
    for j in range(N-2, -1, -1):
        if nex[i][j] != INF:
            continue
        nex[i][j] = nex[i][j+1]

ans = ""
now = 0
for k in range(K, 0, -1):
    for i in range(ord("z")-ord("a")+1):
        pos = nex[i][now]
        if pos <= N - k:
            now = pos + 1
            ans += chr(ord("a") + i)
            break

print(ans)

            