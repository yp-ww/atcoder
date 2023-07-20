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
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> va, vb, vc;
    rep(i, 0, A){ ll p; cin >> p; va.push_back(-p); }
    rep(i, 0, B){ ll q; cin >> q; vb.push_back(-q); }
    rep(i, 0, C){ ll r; cin >> r; vc.push_back(-r); }

    sort(all(va));
    sort(all(vb));
    sort(all(vc));

    priority_queue<ll> hq;
    rep(i, 0, X) hq.push(-va[i]);
    rep(i, 0, Y) hq.push(-vb[i]);
    rep(i, 0, C) hq.push(-vc[i]);

    ll ans = 0;
    rep(i, 0, X+Y){
        ans += hq.top(); hq.pop();
    }

    cout << ans << endl;

    return 0;
}