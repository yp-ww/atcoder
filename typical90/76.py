import io
import sys
_INPUT = """\
3
1 1 1

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())
A = list(map(int, input().split()))

M = sum(A)
if M//10 == 0:
    print("No")
    exit(0)

A += A
cum = [0]
for i in range(2*N):
    cum.append(cum[-1] + A[i])

l = 0
r = 1
while l <= N and l+N >= r:
    # print(l, r)
    if cum[r] - cum[l] == M//10:
        print("Yes")
        exit(0)

    elif cum[r] - cum[l] < M//10:
        r += 1

    else:
        l += 1
    
print("No")


   