import io
import sys
_INPUT = """\
42

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from sys import stdin
input=lambda :stdin.readline()[:-1]

K = int(input())

cnt = 0
for a in range(1, 10**4+1):
    if K % a:
        continue
    for b in range(a, 10**6+1):
        if (K//a) % b:
            continue
        c = K // (a*b)
        if b > c:
            break
        cnt += 1

print(cnt)