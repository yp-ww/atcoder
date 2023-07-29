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
const ll INF = (ll)1e20;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N, K;
    cin >> N >> K;
    vector<ll> X(N);
    rep(i, 0, N) cin >> X[i];

    vector<ll> mi, pr;
    mi.push_back(0);
    pr.push_back(0);
    rep(i, 0, N){
        ll x = X[i];
        if (x < 0){
            mi.push_back(-x);
        }else{
            pr.push_back(x);
        }
    }

    sort(all(mi));
    sort(all(pr));

    int n = mi.size();
    int m = pr.size();
    
    ll ans = INF;
    rep(i, 0, n) {
        int j = K - i;
        if (0 <= j && j < m){
            chmin(ans, mi[i]*2 + pr[j]);
            chmin(ans, pr[j]*2 + mi[i]);
        }
    }
    // rep(i, 0, m) {
    //     int j = K - i;
    //     if (0 <= j && j < n) chmin(ans, pr[i]*2 + mi[j]);
    // }

    cout << ans << endl;
    return 0;
}