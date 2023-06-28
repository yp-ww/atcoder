import io
import sys
_INPUT = """\

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())

st = set()
ans = []
for i in range(1, N+1):
    s = input()
    if s in st:
        continue
    ans.append(i)
    st.add(s)

for a in ans:
    print(a)

