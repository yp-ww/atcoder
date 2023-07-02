import io
import sys
_INPUT = """\
3 2
red green blue
blue red
800 1600 2800

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from collections import defaultdict
N, M = map(int, input().split())
C = list(input().split())
D = list(input().split())
P = list(map(int, input().split()))

st = set()
d = defaultdict(int)
for i in range(M):
    st.add(D[i])
    d[D[i]] = P[i+1]
# print(d)

ans = 0
for c in C:
    # print(c)
    if c in st:
        ans += d[c]
    else:
        ans += P[0]

print(ans)

    