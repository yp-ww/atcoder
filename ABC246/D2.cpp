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

    auto f = [](ll a, ll b){
        return a*a*a + a*a*b + a*b*b + b*b*b;
    };

    ll MAX = 1001000;
    ll ans = (ll)1e30;
    rep(i, 0, MAX){
        ll a = (ll)i;
        ll l = a-1;
        ll r = MAX;
        
        while (r - l > 1){
            ll mid = (l + r) / 2;
            if (f(a, mid) >= N){
                r = mid;
            }else{
                l = mid;
            }
        }
        chmin(ans, f(a, r));
    }

    cout << ans << endl;
    return 0;
}