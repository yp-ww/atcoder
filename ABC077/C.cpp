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
    int N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, N) cin >> C[i];

    sort(all(A));
    sort(all(B));
    sort(all(C));

    ll ans = 0LL;
    rep(i, 0, N){
        ll b = B[i];
        auto ita = lower_bound(all(A), b);
        int ia = ita - A.begin();
        auto itc = upper_bound(all(C), b);
        int ic = itc - C.begin();

        ans += ((ll)ia * (ll)(N-ic));
    }

    cout << ans << endl;

    return 0;
}