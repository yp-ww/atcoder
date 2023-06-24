#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
 
int N;
ll A[300300];
ll dp[300300];
ll dp2[300300];
 
int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i%N];
    }
 
    for (int i=0; i<300300; i++){
        dp[i] = 1e16;
        dp2[i] = 1e16;
    }
 
    // mode1
    dp[2] = A[1];
    for (int i=2; i<N; i++){
        dp[i+1] = min(dp[i+1], A[i] + dp[i]);
        dp[i+2] = min(dp[i+2], A[(i+1)%N] + dp[i]);
    }
    ll ans = dp[N];
    ans = min(ans, dp[N+1]);
 
    // cout << ans << endl;
 
    // mode2
    dp2[1] = A[0];
    for (int i=1; i<N-1; i++){
        dp2[i+1] = min(dp2[i+1], A[i] + dp2[i]);
        dp2[i+2] = min(dp2[i+2], A[(i+1)%N] + dp2[i]);
    }
    ans = min(ans, dp2[N-1]);
    ans = min(ans, dp2[N]);
 
    cout << ans << endl;
 
    return 0;
}