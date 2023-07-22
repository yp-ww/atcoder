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
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> X(N);
    rep(i, 0, N) cin >> X[i];

    ll INF = (ll)1e15;
    vector<ll> dp(N, INF);

    dp[0] = 0;
    rep(i, 0, N-1){
        chmin(dp[i+1], dp[i] + (X[i+1] - X[i]) * A);
        chmin(dp[i+1], dp[i] + B);
    }

    cout << dp[N-1] << endl;

    return 0;
}