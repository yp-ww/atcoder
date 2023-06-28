import io
import sys
_INPUT = """\

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())

s1 = [0] * (N+1)
s2 = [0] * (N+1)
for i in range(N):
    c, p = map(int, input().split())
    if c == 1:
        s1[i+1] = p
    else:
        s2[i+1] = p

for i in range(1, N+1):
    s1[i] += s1[i-1]
    s2[i] += s2[i-1]

Q = int(input())
for i in range(Q):
    l, r = map(int, input().split())
    ans1 = s1[r] - s1[l-1]
    ans2 = s2[r] - s2[l-1]
    print(ans1, ans2)