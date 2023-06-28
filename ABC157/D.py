import io
import sys
_INPUT = """\
4 4 1
2 1
1 3
3 2
3 4
4 1

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N, M, K = map(int, input().split())

par = [i for i in range(N)]
size = [1] * N
indeg = [0] * N
def root(x):
    temp = x
    while x != par[x]:
        x = par[x]
    par[temp] = x
    return x

def unite(x, y):
    x = root(x)
    y = root(y)
    if x == y:
        return 
    
    if size[x] < size[y]:
        x, y = y, x
    par[y] = x
    size[x] += size[y]
    return 

for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    indeg[a] += 1
    indeg[b] += 1
    unite(a, b)


ans = [0] * N
for i in range(N):
    ans[i] += size[root(i)] - 1
    ans[i] -= indeg[i]

for i in range(K):
    c, d = map(int, input().split())
    c -= 1
    d -= 1
    if par[c] == par[d]:
        ans[c] -= 1
        ans[d] -= 1

print(*ans)
