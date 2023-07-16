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

ll f(vector<ll> A, ll x){
    int n = A.size();
    ll res = 0;
    rep(i, 0, n-1){
        ll now = A[i];
        ll nex = A[i+1];
        ll s = now + nex;
        if (s <= x) continue;
        ll d = s - x;
        res += d;
        if (d < nex){
            A[i+1] -= d;
        }else{
            A[i+1] = 0;
            d -= nex;
            A[i] -= d;
        }
    }
    return res;
}

int main()
{
    ll N, x;
    cin >> N >> x;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    ll ans = f(A, x);
    reverse(all(A));
    chmin(ans, f(A, x));

    cout << ans << endl;

    return 0;
}