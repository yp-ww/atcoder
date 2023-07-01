import io
import sys
_INPUT = """\
8 5
6 17 2 4 17 19 1 7
2 0 0
1 7 2
1 2 6
1 4 5
3 4 0



"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, Q = map(int, input().split())
A = list(map(int, input().split()))

pos = 0
for _ in range(Q):
    t, x, y = map(int, input().split())
    x -= 1
    y -= 1
    if t == 1:
        # print(A, A[(pos+x)%N], A[(pos+y)%N])
        A[(pos+x)%N], A[(pos+y)%N] = A[(pos+y)%N], A[(pos+x)%N]
    if t == 2:
        pos -= 1
        pos %= N

    if t == 3:
        print(A[(pos+x)%N])
    
