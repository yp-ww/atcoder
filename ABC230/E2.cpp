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

    set<pair<ll, ll>> st;
    for (ll i=1; i*i<=N; i++){
        ll x = i;
        ll y = N / x;
        st.insert(make_pair(x, y));
        st.insert(make_pair(y, x));
    }

    ll ans = 0LL;
    ll pre = 0LL;
    for (auto p: st){
        ll x = p.first;
        ll y = p.second;
        ans += (x - pre) * y;
        pre = x;
    }

    cout << ans << endl;

    return 0;
}