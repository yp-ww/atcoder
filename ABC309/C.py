import io
import sys
_INPUT = """\
4 8
6 3
2 5
1 9
4 2

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

N, K = map(int, input().split())
AB = []
for _ in range(N):
    a, b = map(int, input().split())
    AB.append((a, b))

def f(x):
    cnt = 0
    for a, b in AB:
        if x <= a:
            cnt += b
    return cnt

l = 0
r = 10 ** 9 + 1
while r - l > 1:
    mid = (l + r) // 2
    if f(mid) > K:
        l = mid
    else:
        r = mid

print(r)