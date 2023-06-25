import io
import sys
_INPUT = """\
6
"""
sys.stdin = io.StringIO(_INPUT)

# Anser
W = int(input())

b = 100

arr = [i for i in range(1, b)]

ans = [i for i in range(1, b)]
for i in range(b-1):
    a = arr[i]
    for j in range(1, 3):
        ans.append(a * (b**j))

print(len(ans[:min(W, 300)]))
ans.sort()
print(*ans[:min(W, 300)])

