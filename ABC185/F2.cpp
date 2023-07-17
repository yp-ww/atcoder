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

ll op(ll a, ll b){return a ^ b;}
ll e(){return 0;}

int main()
{
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    segtree<ll, op, e> seg(N);
    rep(i, 0, N) seg.set(i, A[i]);
    
    rep(i, 0, Q){
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1){
            x--;
            seg.set(x, seg.get(x)^y);
        }else{
            x--; y--;
            ll ans = seg.prod(x, y+1);
            cout << ans << endl;
        }
    }

    return 0;
}