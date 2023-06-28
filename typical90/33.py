import io
import sys
_INPUT = """\
1 5
"""
sys.stdin = io.StringIO(_INPUT)

# Anser
H, W = map(int, input().split())

if (H == 1 or W == 1):
    print(H * W)
else:
    ans = ((H+1) // 2) * ((W+1) // 2)
    print(ans)