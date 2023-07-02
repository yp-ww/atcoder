import io
import sys
_INPUT = """\
15
1 1 2 0 0 2 0 2 0 0 0 0 0 2 2
EXMMXXXEMEXEXMM

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())
A = list(map(int, input().split()))
S = input()

cum = [[0] * (N+1) for _ in range(3)]
xcum = [[0] * (N+1) for _ in range(3)]

for i in range(N):
    for j in range(3):
        cum[j][i+1] = cum[j][i]
        xcum[j][i+1] = xcum[j][i]
    if S[i] == "M":
        j = A[i]
        cum[j][i+1] += 1
    elif S[i] == "X":
        j = A[i]
        xcum[j][i+1] += 1

def mex(a, b, c):
    v = [True] * 4
    v[a] = False
    v[b] = False
    v[c] = False
    for i in range(4):
        if v[i]:
            return i

ans = 0
for i in range(N):
    if S[i] != "E":
        continue
    e = A[i]
    for j in range(3):
        mcnt = cum[j][i]
        for k in range(3):
            xcnt = xcum[k][N] - xcum[k][i+1]
            y = mex(j, e, k)
            ans += (mcnt * xcnt) * y

print(ans)
 







    
