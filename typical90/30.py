import io
import sys
_INPUT = """\
15 2


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

N, K = map(int, input().split())

v = [0] * (N+1)
for i in range(2, N+1):
    if v[i]:
        continue
    p = i
    c = p
    while c <= N:
        v[c] += 1
        c += p 

cnt = 0
for i in range(2, N+1):
    if v[i] >= K:
        cnt += 1

print(cnt)