import io
import sys
_INPUT = """\
5
1 2 3 4 5
1 2 2 4 3
7
1 1
2 2
2 3
3 3
4 4
4 5
5 5

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
q = int(input())

sa = set()
sb = set()
ah = [0]*n
bh = [0]*n
mod = 9999999999999937
for i in range(n):
    if (a[i] not in sa):
        sa.add(a[i])
        ah[i] = a[i]*(a[i]*12854271+51851452)*(a[i]*31742646+511616)%mod
    if (b[i] not in sb):
        sb.add(b[i])
        bh[i] = b[i]*(b[i]*12854271+51851452)*(b[i]*31742646+511616)%mod

am = [0]*(n+1)
bm = [0]*(n+1)
for i in range(n):
    am[i+1]=am[i]+ah[i]
    am[i+1]%=mod
    bm[i+1]=bm[i]+bh[i]
    bm[i+1]%=mod

while q:
    q -= 1
    x,y=map(int,input().split())
    if(am[x]==bm[y]):
        print("Yes")
    else:
        print("No")
