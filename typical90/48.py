import io
import sys
_INPUT = """\
4 3
4 3
9 5
15 8
8 6

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, K = map(int, input().split())

arr = []
for _ in range(N):
    a, b = map(int, input().split())
    arr.append(b)
    arr.append(a-b)

arr.sort(reverse=True)
ans = sum(arr[:K])

print(ans)
