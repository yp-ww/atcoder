import io
import sys
_INPUT = """\
4 7
1 2
2 1
2 3
4 3
4 1
1 4
2 3


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
sys.setrecursionlimit(10**5 + 100)
input=lambda :sys.stdin.readline()[:-1]

N, M = map(int, input().split())

G = [list() for _ in range(N)]
RG = [list() for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    RG[b].append(a)

# 強連結成分分解(SCC): グラフGに対するSCCを行う
# 入力: <N>: 頂点サイズ, <G>: 順方向の有向グラフ, <RG>: 逆方向の有向グラフ
# 出力: (<ラベル数>, <各頂点のラベル番号>)
def scc(N, G, RG):
    order = []
    used = [False] * N
    group = [None] * N

    def dfs(s):
        used[s] = True
        for t in G[s]:
            if used[t]:
                continue
            dfs(t)
        order.append(s)
        return

    def rdfs(s, col):
        group[s] = col
        used[s] = True
        for t in RG[s]:
            if used[t]:
                continue
            rdfs(t, col)
        return 

    for i in range(N):
        if used[i]:
            continue
        dfs(i)

    used = [False] * N
    label = 0
    for s in reversed(order):
        if used[s]:
            continue
        rdfs(s, label)
        label += 1
    return label, group

l, group = scc(N, G, RG)
from collections import defaultdict
d = defaultdict(int)
for g in group:
    d[g] += 1

ans = 0
for key in d:
    c = d[key]
    ans += c * (c-1) // 2

print(ans)

    