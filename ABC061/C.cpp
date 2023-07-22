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
    ll N, K;
    cin >> N >> K;

    vector<pair<ll, ll>> v;
    rep(i, 0, N){
        ll a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(all(v));
    
    ll ans = 0;
    ll pos = 0;
    for (auto p: v){
        auto x = p.first;
        auto y = p.second;
        pos += y;
        if (pos >= K){
            ans = x;
            break;
        }
    }

    cout << ans << endl;
 
    return 0;
}