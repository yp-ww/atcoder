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
    int N, K;
    cin >> N >> K;

    if (K == 0){
        ll ans = (ll)N * N;
        cout << ans << endl;
        return 0;
    }

    ll ans = 0;
    rep(b, K+1, N+1){
        ll n = (N+1) / b;
        ans += (ll)(b-K) * n;
        
        ll l = n*b + K;
        ll r = N;
        if (l <= r) ans += r - l + 1;
    }

    cout << ans << endl;
    return 0;
}