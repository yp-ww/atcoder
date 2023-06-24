import io
import sys
_INPUT = """\
5
5 4 3 3 2 5 3 5 3


"""
sys.stdin = io.StringIO(_INPUT)

# Anser

N = int(input())
C = [0] + list(map(int, input().split()))

c_min = min(C[1:])
l = N // c_min

amari = N % c_min

arr = []
for n in range(l):
    for i in range(9, 0, -1):
        c = C[i]
        if c <= amari + c_min:
            arr.append(i)
            amari -= (c - c_min)
            break
ans = ""
for a in arr:
    ans += str(a)
print(ans)
