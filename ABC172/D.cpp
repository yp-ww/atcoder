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
    ll N;
    cin >> N;

    vector<ll> cnt(N+1, 1);
    rep(i, 2, N+1){
        ll c = (ll)i;
        while (c < N+1){
            cnt[c] += 1;
            c += i;
        }
    }
    ll ans = 0;
    rep(i, 1, N+1){
        ans += (ll)i * cnt[i];
    }
    cout << ans << endl;
    return 0;
}