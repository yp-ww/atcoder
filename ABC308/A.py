import io
import sys
_INPUT = """\
0 23 24 145 301 413 631 632


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
S = list(map(int, input().split()))

pre = 0
for s in S:
    if s % 25:
        print("No")
        exit(0)
    
    if 10 <= s <= 675:
        pass
    else:
        print("No")
        exit(0)

    if pre > s:
        print("No")
        exit(0)
    else:
        pre = s 

print("Yes")     
    
