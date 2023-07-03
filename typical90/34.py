import io
import sys
_INPUT = """\
10 2
1 2 3 4 4 3 2 1 2 3


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from collections import defaultdict
N, K = map(int, input().split())
A = list(map(int, input().split()))

l = 0
r = 0
d = defaultdict(int)
ans = 0
while l < N:
    while r < N:
        if len(d) == K:
            if A[r] in d:
                d[A[r]] += 1
                ans = max(ans, r-l+1)          
                r += 1
            else:
                break
        else:
            d[A[r]] += 1
            ans = max(ans, r-l+1)
            r += 1
    
    d[A[l]] -= 1
    if d[A[l]] == 0:
        del d[A[l]]
    l += 1

print(ans)