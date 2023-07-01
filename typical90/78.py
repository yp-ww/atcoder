import io
import sys
_INPUT = """\

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, M = map(int, input().split())
indeg = [0] * (N+1)

for _ in range(M):
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a
    if a == b:
        continue

    indeg[b] += 1

ans = 0
for i in range(1, N+1):
    if indeg[i] == 1:
        ans += 1

print(ans)