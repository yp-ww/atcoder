import io
import sys
_INPUT = """\
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2
1 3
2 3

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import itertools
N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]
M = int(input())
st = set()
for _ in range(M):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    st.add((x, y))
    st.add((y, x))

INF = 10 ** 30
arr = [i for i in range(N)]
ans = INF
for a in list(itertools.permutations(arr)):
    flag = False
    for i in range(N-1):
        if (a[i], a[i+1]) in st:
            flag = True
            break

    if flag:
        continue

    temp = 0
    for j in range(N):
        temp += A[a[j]][j]

    ans = min(ans, temp)

if ans == INF:
    print(-1)
else:
    print(ans)






