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
    vector<ll> A, B, C;
    rep(i, 0, N){
        ll t, x;
        cin >> t >> x;
        if (t == 0){
            A.push_back(x);
        }else if (t == 1){
            B.push_back(x);
        }else{
            C.push_back(x);
        }
    }

    stable_sort(all(A), [](ll a, ll b){return a > b;});
    stable_sort(all(B), [](ll a, ll b){return a > b;});
    stable_sort(all(C), [](ll a, ll b){return a > b;});
    vector<ll> cum_a(A.size()+1, 0), cum_b(B.size()+1, 0), cum_c(C.size()+1, 0);
    rep(i, 0, A.size()) cum_a[i+1] = cum_a[i] + A[i];
    rep(i, 0, B.size()) cum_b[i+1] = cum_b[i] + B[i];
    rep(i, 0, C.size()) cum_c[i+1] = cum_c[i] + C[i];

    ll ans = 0;
    rep(i, 0, A.size()+1){
        if (i > M) break;
        ll cnt = M - (ll)i;
        ll l = 0;
        ll r = min(cnt+1LL, (ll)B.size()+1LL);
        while (r - l > 1){
            ll mid = (l + r) / 2;
            auto itr = lower_bound(all(cum_c), mid);
            ll cnt_c = itr - cum_c.begin();
            ll tot = cnt_c + mid;
            if (lower_bound(all(cum_c), mid) != cum_c.end() && tot <= cnt){
                l = mid;
            }else{
                r = mid;
            }
        }
        chmax(ans, cum_a[i] + cum_b[l]);
    }

    cout << ans << endl;

    return 0;
}