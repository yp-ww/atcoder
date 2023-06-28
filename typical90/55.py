import io
import sys
_INPUT = """\

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, P, Q = map(int, input().split())
A = list(map(int, input().split()))
ans = 0
for i in range(N):
    a = A[i] % P
    for j in range(i+1, N):
        b = A[j] % P
        for k in range(j+1, N):
            c = A[k] % P
            for l in range(k+1, N):
                d = A[l] % P
                for r in range(l+1, N):
                    e = A[r] % P
                    x = a
                    x *= b
                    x %= P
                    x *= c
                    x %= P
                    x *= d
                    x %= P
                    x *= e
                    x %= P
                    if x == Q:
                        ans += 1
print(ans)