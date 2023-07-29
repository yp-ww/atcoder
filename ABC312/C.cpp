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
const ll INF = (ll)1e15;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, M) cin >> B[i];

    sort(all(A));
    sort(all(B));

    auto f = [&](int x){
        auto ca_itr = upper_bound(all(A), x);
        auto cb_itr = lower_bound(all(B), x);
        int ca = ca_itr - A.begin();
        int cb = cb_itr - B.begin();
        cb = B.size() - cb;
        if (ca >= cb){
            return true;
        }else{
            return false;
        }
    };

    ll l, r;
    l = 0;
    r = (ll)1e9+1;
    while (r - l > 1){
        ll mid = (l + r) / 2;
        if (f(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }

    cout << r << endl;

    return 0;
}