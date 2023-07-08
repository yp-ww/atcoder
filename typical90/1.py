import io
import sys
_INPUT = """\
7 45
2
7 11 16 20 28 34 38


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from sys import stdin
input=lambda :stdin.readline()[:-1]

N, L = map(int, input().split())
K = int(input())
A = list(map(int, input().split()))
A.append(L)

def f(x):
    pre = 0
    temp = 0
    cnt = 0
    for i in range(N+1):
        temp = A[i] - pre
        if temp >= x:
            cnt += 1
            pre = A[i]
            temp = 0

    if cnt > K:
        return True
    else:
        return False

l = 1
r = 10 ** 9 + 1
while r - l > 1:
    mid = (l + r) // 2
    if f(mid):
        l = mid
    else:
        r = mid

print(l)

