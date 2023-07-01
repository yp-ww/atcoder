import io
import sys
_INPUT = """\
4

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())

if N % 2:
    exit()

m = N // 2
t = [("(", 1, 0)]

flag = True
while flag:
    l = len(t)
    temp = []
    for i in range(l):
        s, c0, c1 = t[i]
        if c0 > c1:
            temp.append((s+")", c0, c1+1))
        if c0 < m:
            temp.append((s+"(", c0+1, c1))
        if c0 + c1 == N-1:
            flag = False
    t = temp

ans = []
for s, c0, c1 in t:
    ans.append(s)

ans.sort()
for a in ans:
    print(a)
        


        


