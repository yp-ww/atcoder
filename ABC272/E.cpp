#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N, M;
long long A[300300];
vector<set<int>> st(300300);

int main()
{
    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> A[i];

    for (int i=1; i<N+1; i++){
        long long a = A[i-1];
        long long m = max((long long)1, -a/i);
        int x = a + i*m;
        // cout << x << endl;
        while (x < N+10){
            if (m > M+1) break;
            if (x >= 0) st[m].insert(x);
            m++;
            x = a + i*m;
        }
    }

    for (int m=1; m<M+1; m++){
        for (int x=0; x<N+1; x++){
            if (st[m].find(x) == st[m].end()){
                cout << x << endl;
                break;
            }
        }
    }

    return 0;
}