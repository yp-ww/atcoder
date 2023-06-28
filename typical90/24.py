import io
import sys
_INPUT = """\

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

dif = 0
for i in range(N):
    a = A[i]
    b = B[i]
    dif += abs(a - b)

if dif > K:
    print("No")
elif dif <= K and (K - dif) % 2 == 0:
    print("Yes")
else:
    print("No")