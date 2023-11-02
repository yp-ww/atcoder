import io
import sys
_INPUT = """\
4 2
1 2 3 4
4 3 1 2

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

n,m = map(int,input().split())
a=[list(map(int,input().split())) for _ in range(m)]

v=[[False]*n for _ in range(n)]
for i in range(m):
    for j in range(n-1):
        v[a[i][j]-1][a[i][j+1]-1]=True
        v[a[i][j+1]-1][a[i][j]-1]=True

ans = 0
for i in range(n):
    for j in range(i+1,n):
        if not v[i][j]:
            ans += 1
print(ans)