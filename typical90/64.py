import io
import sys
_INPUT = """\
20 10
61 51 92 -100 -89 -65 -89 -64 -74 7 87 -2 51 -39 -50 63 -23 36 74 37
2 2 -45
6 19 82
2 9 36
7 13 71
16 20 90
18 20 -24
14 17 -78
10 11 -55
7 19 -26
20 20 -7


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, Q = map(int, input().split())
A = list(map(int, input().split()))

ans = 0
arr = [0] * (N-1)
for i in range(N-1):
    ans += abs(A[i]-A[i+1])
    arr[i] = A[i]-A[i+1]

for i in range(Q):
    l, r, v = map(int, input().split())
    l -= 1
    r -= 1
    if l == 0 and r == N-1:
        print(ans)

    elif l == 0:
        ans -= abs(arr[r])
        arr[r] += v
        ans += abs(arr[r])
        print(ans)
    
    elif r == N-1:
        ans -= abs(arr[l-1])
        arr[l-1] -= v
        ans += abs(arr[l-1])
        print(ans)

    else:
        ans -= abs(arr[r])
        arr[r] += v
        ans += abs(arr[r])
        ans -= abs(arr[l-1])
        arr[l-1] -= v
        ans += abs(arr[l-1])

        print(ans)

