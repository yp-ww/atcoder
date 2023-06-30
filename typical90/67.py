import io
import sys
_INPUT = """\
21 1

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, K = map(int, input().split())

def f(x):
    x10 = 0
    for i in range(21):
        y = (x//(10**i)) % 10
        x10 += (8 ** i) * y

    x9 = 0
    for i in range(21):
        temp = x10 % 9
        if temp == 8:
            temp = 5
        x9 += temp * (10 ** i)
        x10 //= 9

    return x9

ans = N
for i in range(K):
    ans = f(ans)

print(ans)