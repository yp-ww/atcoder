import io
import sys
_INPUT = """\
6
2 3 3 1 3 1

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from collections import defaultdict
N = int(input())
A = list(map(int, input().split()))

d = defaultdict(int)
for i in range(N):
    a = A[i]
    # j - Aj
    if i+1-a < 0:
        continue
    d[i+1 - a] += 1

ans = 0
for i in range(N):
    a = A[i]
    b = a + i + 1
    ans += d[b]

print(ans)


