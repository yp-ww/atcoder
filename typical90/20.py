import io
import sys
_INPUT = """\
8 3 2

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
a, b, c = map(int, input().split())
if a < c ** b:
    print("Yes")
else:
    print("No")