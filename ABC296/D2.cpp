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
    ll N, M;
    cin >> N >> M;

    ll INF = (ll)1e16;
    ll ans = INF;
    ll a = 1;
    while (a < min(N, (ll)1e6)+1){
        ll b = (M + a - 1) / a;
        if (a > b) {break;}
        if (b > N) {a++; continue;}
        if (M <= a*b) {chmin(ans, a*b); a++;}
    }

    if (ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}