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
    int T;
    cin >> T;

    rep(i, 0, T){
        ll N, D, K;
        cin >> N >> D >> K;
        K--;

        ll cnt = N / gcd(N, D);
        ll x = K / cnt;
        ll y = K % cnt;
        ll ans = (x + D * y) % N;
        cout << ans << endl;
    }
  

    return 0;
}