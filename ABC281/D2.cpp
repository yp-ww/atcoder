#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N, K, D;
    cin >> N >> K >> D;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(K+1, vector<ll>(D, -1)));
    
    dp[0][0][0] = 0;
    rep(i, 0, N) rep(j, 0, K+1){
        rep(k, 0, D){
            if (dp[i][j][k] == -1) continue;
            chmax(dp[i+1][j][k], dp[i][j][k]);
            if (j+1 <= K){
                chmax(dp[i+1][j+1][(k+A[i])%D], dp[i][j][k] + A[i]);
            }
        }
    }

    cout << dp[N][K][0] << endl;

    return 0;
}