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
    ll N;
    cin >> N;
    vector<ll> T(N), X(N), A(N);
    rep(i, 0, N) cin >> T[i] >> X[i] >> A[i];

    ll INF = (ll)1e15;
    vector<vector<ll>> dp(N+1, vector<ll>(5, -INF));
    
    dp[0][0] = 0;
    ll now = 0;
    rep(i, 0, N){
        ll t = T[i];
        ll x = X[i];
        rep(j, 0, 5){
            int d = t-now;
            rep(k, max(j-d, 0), min(j+d+1, 5)){
                if (k == x){
                    chmax(dp[i+1][k], dp[i][j] + A[i]);
                }else{
                    chmax(dp[i+1][k], dp[i][j]);
                }
            }
        }
        now = t;
    }

    ll ans = *max_element(all(dp[N]));
    cout << ans << endl;

    return 0;
}