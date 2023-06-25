import io
import sys
_INPUT = """\
a
b
c

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
from itertools import permutations
from collections import defaultdict
S1 = input()
S2 = input()
S3 = input()

d = defaultdict(int)
ng = []
cnt = -1
for S in [S1, S2, S3]:
    for i in range(len(S)):
        s = S[i]
        if s in d:
            continue
        cnt += 1
        d[s] = cnt
        if i == 0:
            ng.append(cnt)

if cnt >= 10:
    print("UNSOLVABLE")
    exit(0)

arr = [i for i in range(10)]
s1 = S1[len(S1)-1]
s2 = S2[len(S2)-1]
s3 = S3[len(S3)-1]
for ar in list(permutations(arr)):
    flag = False
    for j in ng:
        if ar[j] == 0:
            flag = True
            break
    
    if (ar[d[s1]] + ar[d[s2]]) % 10 != ar[d[s3]]:
        flag = True
    
    if flag:
        continue
    ans = []
    for S in [S1, S2, S3]:
        x = 0
        for i in range(len(S)):
            s = S[i]
            num = ar[d[s]]
            if i == 0 and num == 0:
                flag = True
                break
            x += num * (10 ** (len(S)-i-1))
        if flag:
            break
        ans.append(x)
    if flag:
        continue

    if ans[0] + ans[1] == ans[2]:
        print(ans[0])
        print(ans[1])
        print(ans[2])
        exit(0)

print("UNSOLVABLE")
        