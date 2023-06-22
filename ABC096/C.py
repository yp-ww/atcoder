import io
import sys
_INPUT = """\
3 3
.#.
###
.#.

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]

dxdy = [(-1, 0), (1, 0), (0, -1), (0, 1)]

for i in range(H):
    for j in range(W):
        if S[i][j] == ".":
            continue
        flag = True
        for dx, dy in dxdy:
            if i + dy < 0 or H <= i + dy:
                continue
            if j + dx < 0 or W <= j + dx:
                continue
            if S[i+dy][j+dx] == "#":
                flag = False

        if flag:
            print("No")
            exit(0)
print("Yes")
        
