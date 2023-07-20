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
    int N, K;
    cin >> N >> K;

    ll cnt = 0;
    vector<bool> v(N+1);
    rep(i, 1, N+1){
        if (i % K == 0) {cnt++; v[i] = true;}
    }

    ll ans = cnt * cnt * cnt;

    cnt = 0;
    if (K % 2 == 0){
        K /= 2;
        rep(i, 1, N+1){
            if (v[i]) continue;
            if (i % K == 0) cnt++;
        }
    }

    ans += cnt * cnt * cnt;

    cout << ans << endl;

    return 0;
}