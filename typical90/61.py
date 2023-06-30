import io
import sys
_INPUT = """\

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
Q = int(input())
from collections import deque

q = deque()

for _ in range(Q):
    t, x = map(int, input().split())
    if t == 1:
        q.appendleft(x)
    if t == 2:
        q.append(x)
    if t == 3:
        x -= 1
        print(q[x])
    