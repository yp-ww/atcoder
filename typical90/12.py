import io
import sys
_INPUT = """\
3 3
10
1 2 2
1 1 1
2 1 1 2 2
1 3 2
2 1 1 2 2
2 2 2 3 2
1 2 3
1 2 1
2 1 1 2 2
2 1 1 3 3

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
H, W = map(int, input().split())
Q = int(input())

def cv(h, w):
    return W * h + w

N = H * W

par = [-1] * N
size = [1] * N
def root(x):
    if par[x] == -1:
        return x
    else:
        par[x] = root(par[x])
        return par[x]

def unite(x, y):
    x = root(x)
    y = root(y)
    if x == y:
        return False
    
    # union by size
    if size[x] < size[y]:
        x, y = y, x
    par[y] = x
    size[x] += size[y]
    return True

v = [[False] * W for _ in range(H)]

for _ in range(Q):
    q = list(map(int, input().split()))
    if q[0] == 1:
        h = q[1] - 1
        w = q[2] - 1
        v[h][w] = True
        for dh, dw in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nh = h + dh
            nw = w + dw
            if 0 <= nh < H and 0 <= nw < W and v[nh][nw]:
                unite(cv(h, w), cv(nh, nw))

    else:
        h1 = q[1] - 1
        w1 = q[2] - 1
        h2 = q[3] - 1 
        w2 = q[4] - 1
        if v[h1][w1] and v[h2][w2] and root(cv(h1, w1)) == root(cv(h2, w2)):
            print("Yes")
        else:
            print("No")
