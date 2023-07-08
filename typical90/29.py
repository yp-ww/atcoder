import io
import sys
_INPUT = """\
500000 7
1 500000
500000 500000
1 500000
1 1
1 500000
500000 500000
1 500000


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

W, N = map(int, input().split())
arr = set()
LR = []
for _ in range(N):
    l, r = map(int, input().split())
    l -= 1
    LR.append((l, r))
    arr.add(l)
    arr.add(r)
arr = list(arr)
arr.sort()
from collections import defaultdict
d = defaultdict(int)
cnt = 0
for a in arr:
    d[a] = cnt
    cnt += 1


LEN = len(d)

sz = 1
while sz < LEN:
    sz *= 2

node = [0] * sz * 2
lazy = [0] * sz * 2

# 遅延評価関数
def eval(a, b, n):
    # 遅延配列が空の場合、処理を抜ける
    if lazy[n] == 0:
        return 
    
    # 最下段の場合、値を反映
    node[n] = max(node[n], lazy[n]) # 区間最大値
    if b - a <= 1:
        return 
    
    # 値の伝搬
    lazy[2*n] = max(lazy[2*n], lazy[n]) # 区間最大値
    lazy[2*n+1] = max(lazy[2*n+1], lazy[n]) # 区間最大値
    lazy[n] = 0
    return

# 区間更新
def update(l, r, x, a, b, n):
    # 遅延評価
    eval(a, b, n)

    if r <= a or b <= l:
        return
    
    if l <= a and b <= r:
        lazy[n] = x
        eval(a, b, n)
        return

    mid = (a + b) // 2
    update(l, r, x, a, mid, n*2)
    update(l, r, x, mid, b, n*2+1)
    node[n] = max(node[2*n], node[2*n+1]) # 区間最大値
    return 

# 区間最大値の取得
def query(l, r, a, b, n):
    if r <= a or b <= l:
        return 0
    
    # 遅延評価
    eval(a, b, n)

    if l <= a and b <= r:
        return node[n]
    
    mid = (a + b) // 2
    vl = query(l, r, a, mid, n*2)
    vr = query(l, r, mid, b, n*2+1)
    return max(vl, vr)  # 区間最大値

for l, r in LR:
    l = d[l]
    r = d[r]
    h = query(l, r, 0, sz, 1)
    print(h+1)
    update(l, r, h+1, 0, sz, 1)
