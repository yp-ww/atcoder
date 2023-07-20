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
    ll N, D;
    cin >> N >> D;
    vector<ll> L(N), R(N);
    rep(i, 0, N) cin >> L[i] >> R[i];

    vector<pair<ll, ll>> v;
    rep(i, 0, N) v.push_back(make_pair(R[i], L[i]));
    sort(all(v));
    
    ll pos = -1;
    int ans = 0;
    for (auto p: v){
        auto r = p.first;
        auto l = p.second;
        if (pos >= l) continue;
        ans++;
        pos = r + D - 1;
    }

    cout << ans << endl;
    
    return 0;
}