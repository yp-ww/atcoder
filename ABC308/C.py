import io
import sys
_INPUT = """\
4
999999999 1000000000
333333333 999999999
1000000000 999999997
999999998 1000000000


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from functools import cmp_to_key
N = int(input())

def cmp(x, y):
    a1, ab1, i1 = x
    a2, ab2, i2 = y

    c1 = a1 * ab2
    c2 = a2 * ab1
    if c1 < c2:
        return 1
    elif c1 == c2:
        return -1 if i1 < i2 else 1
    else:
        return -1
    
arr = []
for i in range(N):
    a, b = map(int, input().split())
    arr.append((a, a+b, i+1))

arr.sort(key=cmp_to_key(cmp))
# print(arr)
ans = []
for a, b, c in arr:
    ans.append(c)
print(*ans)