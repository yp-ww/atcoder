import io
import sys
_INPUT = """\
4
ooxo


"""
sys.stdin = io.StringIO(_INPUT)

# Anser
N = int(input())
S = input()
cnt = [0]
for i in range(N):
    if S[i] == "o":
        cnt.append(cnt[-1] + 1)
    else:
        cnt.append(cnt[-1])

# [l, r]
def f(l, r):
    if cnt[r+1] - cnt[l] == 0 or cnt[r+1] - cnt[l] == r-l+1:
        return False
    else:
        return True

ans = 0
for i in range(N-1):
    l = i
    r = N
    while r - l > 1:
        mid = (l + r) // 2
        if f(i, mid):
            r = mid
        else:
            l = mid
    
    if r == N:
        continue
    ans += (N - r)

print(ans)

    
        
