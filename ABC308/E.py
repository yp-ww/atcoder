import io
import sys
_INPUT = """\
15
1 1 2 0 0 2 0 2 0 0 0 0 0 2 2
EXMMXXXEMEXEXMM

"""
sys.stdin = io.StringIO(_INPUT)

# Anser
import bisect
N = int(input())
A = list(map(int, input().split()))
S = input()

x0 = []
x1 = []
x2 = []

for i in range(N):
    if S[i] == "X":
        if A[i] == 0:
            x0.append(i)
        elif A[i] == 1:
            x1.append(i)
        else:
            x2.append(i)

e00 = []
e00s = [0]
e01 = []
e01s = [0]
e02 = []
e02s = [0]
e10 = []
e10s = [0]
e11 = []
e11s = [0]
e12 = []
e12s = [0]
e20 = []
e20s = [0]
e21 = []
e21s = [0]
e22 = []
e22s = [0]
for i in range(N):
    if S[i] == "E":
        if A[i] == 0:
            idx = bisect.bisect_left(x0, i)
            cnt = len(x0) - idx
            if cnt:
                e00.append(i)
                e00s.append(e00s[-1]+cnt)

            idx = bisect.bisect_left(x1, i)
            cnt = len(x1) - idx
            if cnt:            
                e01.append(i)
                e01s.append(e01s[-1]+cnt)       

            idx = bisect.bisect_left(x2, i)
            cnt = len(x2) - idx
            if cnt:
                e02.append(i)
                e02s.append(e02s[-1]+cnt)    

        elif A[i] == 1:
            idx = bisect.bisect_left(x0, i)
            cnt = len(x0) - idx
            if cnt:
                e10.append(i)
                e10s.append(e10s[-1]+cnt)   

            idx = bisect.bisect_left(x1, i)
            cnt = len(x1) - idx
            if cnt:
                e11.append(i)
                e11s.append(e11s[-1]+cnt)   

            idx = bisect.bisect_left(x2, i)
            cnt = len(x2) - idx
            if cnt:
                e12.append(i)
                e12s.append(e12s[-1]+cnt)   

        else:
            idx = bisect.bisect_left(x0, i)
            cnt = len(x0) - idx
            if cnt:
                e20.append(i)
                e20s.append(e20s[-1]+cnt)

            idx = bisect.bisect_left(x1, i)
            cnt = len(x1) - idx
            if cnt:
                e21.append(i)
                e21s.append(e21s[-1]+cnt)

            idx = bisect.bisect_left(x2, i)
            cnt = len(x2) - idx
            if cnt:
                e22.append(i)
                e22s.append(e22s[-1]+cnt)

bisect.bisect_left(e00, 1)

ans = 0
for i in range(N):
    if S[i] == "M":
        if A[i] == 0:
            cnt = 0
            cnt += e00s[len(e00)] - e00s[bisect.bisect_left(e00, i)]
            cnt += e02s[len(e02)] - e02s[bisect.bisect_left(e02, i)]
            cnt += e20s[len(e20)] - e20s[bisect.bisect_left(e20, i)]
            cnt += e22s[len(e22)] - e22s[bisect.bisect_left(e22, i)]
            ans += cnt * 1

            cnt = 0
            cnt += e01s[len(e01)] - e01s[bisect.bisect_left(e01, i)]
            cnt += e10s[len(e10)] - e10s[bisect.bisect_left(e10, i)]
            cnt += e11s[len(e11)] - e11s[bisect.bisect_left(e11, i)]
            ans += cnt * 2

            cnt = 0
            cnt += e12s[len(e12)] - e12s[bisect.bisect_left(e12, i)]
            cnt += e21s[len(e21)] - e21s[bisect.bisect_left(e21, i)]
            ans += cnt * 3
        
        elif A[i] == 1:
            cnt = 0
            cnt += e00s[len(e00)] - e00s[bisect.bisect_left(e00, i)]
            cnt += e01s[len(e01)] - e01s[bisect.bisect_left(e01, i)]
            cnt += e10s[len(e10)] - e10s[bisect.bisect_left(e10, i)]
            ans += cnt * 2

            cnt = 0
            cnt += e02s[len(e02)] - e02s[bisect.bisect_left(e02, i)]
            cnt += e20s[len(e20)] - e20s[bisect.bisect_left(e20, i)]
            ans += cnt * 3

        else:
            cnt = 0
            cnt += e00s[len(e00)] - e00s[bisect.bisect_left(e00, i)]
            cnt += e02s[len(e02)] - e02s[bisect.bisect_left(e02, i)]
            cnt += e20s[len(e20)] - e20s[bisect.bisect_left(e20, i)]
            ans += cnt * 1

            cnt = 0
            cnt += e01s[len(e01)] - e01s[bisect.bisect_left(e01, i)]
            cnt += e10s[len(e10)] - e10s[bisect.bisect_left(e10, i)]
            ans += cnt * 3

print(ans)


                    
