import io
import sys
_INPUT = """\
7 8

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import sys
# sys.setrecursionlimit(10**5)
input=lambda :sys.stdin.readline()[:-1]

A, B = map(int, input().split())

if (A-1)//3 == (B-1)//3 and A+1 == B:
    print("Yes")
    exit(0)

if (A-1)//3 == (B-1)//3 and B-1 == A:
    print("Yes")
    exit(0)

print("No")