import io
import sys
_INPUT = """\
4
4000 4400 5000 3200
3
3312
2992
4229

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import bisect 
N = int(input())
A = list(map(int, input().split()))

Q = int(input())

A.sort()

for _ in range(Q):
    ans = 0
    b = int(input())
    idx = bisect.bisect_left(A, b)
    if idx == N:
        ans += abs(b-A[-1])
    elif idx == 0:
        ans += abs(b-A[0])
    else:
        ans += min(abs(b-A[idx]), abs(b-A[idx-1]))
    print(ans)