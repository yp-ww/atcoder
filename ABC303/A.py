import io
import sys
_INPUT = """\

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

n = int(input())
s = input()
t = input()

flag = True
for i in range(n):
    if (s[i]!=t[i]):
        if (s[i]=='1' and t[i]=='l'):
            continue
        if (t[i]=='1' and s[i]=='l'):
            continue
        if (s[i]=='0' and t[i]=='o'):
            continue
        if (t[i]=='0' and s[i]=='o'):
            continue
        flag = False
if flag:
    print("Yes")
else:
    print("No")