import io
import sys
_INPUT = """\
324
"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

flag = False
n = int(input())
for x in range(0,65):
    for y in range(0, 65):
        if (pow(2,x)*pow(3,y)>n):
            break
        if (pow(2,x)*pow(3,y)==n):
            flag = True
if (flag):
    print("Yes")
else:
    print("No")