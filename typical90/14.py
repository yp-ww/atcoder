import io
import sys
_INPUT = """\

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort()
ans = 0
for i in range(N):
    ans += abs(A[i] - B[i])

print(ans)