import io
import sys
_INPUT = """\
5 2 1 5
LDRLD
0 0
-1 -1

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

n,m,h,k=map(int,input().split())
s=input()

st = set()
for _ in range(m):
    x,y=map(int,input().split())
    st.add((x,y))

now = [0,0]
for i in range(n):
    if s[i]=='R':
        now[0] += 1
        h -= 1
        if (h>k):
            continue
        if (h<0):
            print("No")
            exit()
        if (now[0],now[1]) in st:
            st.discard((now[0],now[1]))
            h = k
    elif s[i]=='L':
        now[0] -= 1
        h -= 1
        if (h>k):
            continue
        if (h<0):
            print("No")
            exit()
        if (now[0],now[1]) in st:
            st.discard((now[0],now[1]))
            h = k
    elif s[i]=='U':
        now[1] += 1
        h -= 1
        if (h>k):
            continue
        if (h<0):
            print("No")
            exit()
        if (now[0],now[1]) in st:
            st.discard((now[0],now[1]))
            h = k
    else:
        now[1] -= 1 
        h -= 1
        if (h>k):
            continue
        if (h<0):
            print("No")
            exit()
        if (now[0],now[1]) in st:
            st.discard((now[0],now[1]))
            h = k
    

print("Yes")