import io
import sys
_INPUT = """\
4 6
1 1 1 1 1 2
1 2 2 2 2 2
1 2 2 3 2 3
1 2 3 2 2 3


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from collections import defaultdict
from sys import stdin
input=lambda :stdin.readline()[:-1]

H, W = map(int, input().split())
P = [list(map(int, input().split())) for _ in range(H)]

ans = 0
for bit in range(1, 1<<H):
    h = []
    for i in range(H):
        if bit & (1<<i):
            h.append(i)

    d = defaultdict(int)
    for j in range(W):
        temp = P[h[0]][j]
        flag = True
        for i in range(1, len(h)):
            if P[h[i]][j] != temp:
                flag = False
                break
        if flag:
            d[temp] += len(h)
            ans = max(ans, d[temp])

print(ans)
    

    

        

