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
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    sort(A.begin(), A.end());

    vector<ll> cum(N+1, 0);
    rep(i, 0, N) cum[i+1] = cum[i] + A[i];

    ll ans = 0;
    rep(i, 0, N){
        ll tot = cum[N] - cum[i+1];
        ans += tot - A[i]*(N-i-1);
    }
    cout << ans << endl;
    return 0;
}
