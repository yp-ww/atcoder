#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()

const double pi = 3.141592653589793;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    ll INF = (ll)1e12;
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, -INF));
    dp[0][0] = 0;
    rep(i, 0, N){
        rep(j, 0, M+1){
            if (i < j) break;
            chmax(dp[i+1][j], dp[i][j]);
            if (j+1 < M+1) chmax(dp[i+1][j+1], dp[i][j] + (ll)(j+1) * A[i]);
        }
    }
    cout << dp[N][M] << endl;

    return 0;
}