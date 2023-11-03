import sys
sys.setrecursionlimit(10**5)

n,p,q=map(int,input().split())
d = list(map(int,input().split()))

ans=p
for i in range(n):
    ans = min(ans, q+d[i])

print(ans)