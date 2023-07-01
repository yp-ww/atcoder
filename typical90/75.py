import io
import sys
_INPUT = """\
12

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())

P = [False] * (10**6+1)
cnt = 0
for i in range(2, 10**6+1):
    if P[i]:
        continue
    p = i
    c = p
    while c < 10**6+1:
        P[c] = True
        c += p

    while N % p == 0:
        N //= p
        cnt += 1

if N != 1:
    cnt += 1
    
for i in range(1000):
    if (2 ** i) >= cnt:
        print(i)
        break
