import io
import sys
_INPUT = """\
10 1
LLLLLRRRRR

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
def runLengthEncoding(s):
    n = len(s)
    res = []
    l = 0
    while l < n:
        r = l + 1
        while r < n and s[l] == s[r]:
            r += 1
        res.append((s[l], r-l))
        l = r
    return res

N, K = map(int, input().split())
S = input()

T = runLengthEncoding(S)

gr = len(T)
for k in range(K):
    if 3 <= gr:
        gr -= 2
    elif gr == 2:
        gr -= 1

ans = N - gr
print(ans)

    