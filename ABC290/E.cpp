#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

long long N;
vector<vector<long long>> P(200200);

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++){
        long long x;
        cin >> x;
        P[x].push_back(i);
    }

    long long ans = 0;
    for (long long i=1; i<=N; i++){
        ans += (N-i+1) * (i/2);
    }

    for (long long x=1; x<=N; x++){
        long long l = 0;
        long long r = P[x].size()-1;
        while (l < r){
            if (P[x][l] < N+1-P[x][r]){
                ans -= (r - l) * P[x][l];
                l++;
            }else{
                ans -= (r - l) * (N + 1 - P[x][r]);
                r--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}