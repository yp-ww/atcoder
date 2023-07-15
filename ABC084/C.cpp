#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    ll N;
    cin >> N;
    vector<ll> C(N), S(N), F(N);
    rep(i, 0, N-1) cin >> C[i] >> S[i] >> F[i];

    rep(i, 0, N){
        ll ans = S[i] + C[i];
        rep(j, i+1, N-1){
            ll l = -1;
            ll r = (ll)1e9;
            while (r - l > 1){
                ll mid = (l + r) / 2;
                ll time = S[j] + F[j] * mid;
                if (time >= ans){
                    r = mid;
                }else{
                    l = mid;
                }
            }
            ans = S[j] + F[j] * r + C[j];
        }
        cout << ans << endl;
    }

    return 0;
}