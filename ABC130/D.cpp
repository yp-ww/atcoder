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
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<ll> cum(N+1, 0);
    rep(i, 0, N) cum[i+1] = cum[i] + A[i];
    
    ll ans = 0;
    rep(i, 0, N){
        ll l = i-1;
        ll r = N-1;
        if (cum[r+1] - cum[i] < K) break;
        while (r - l > 1){
            ll mid = (l + r) / (ll)2;
            ll temp = cum[mid+1] - cum[i];
            if (temp >= K){
                r = mid;
            }else{
                l = mid;
            }
        }
        ans += (N-r);
    }

    cout << ans << endl;
    
    return 0;
}