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

    ll ans = (ll)1e15;
    for (ll i=1; i*i<=N; i++){
        ll a = i;
        if (N % a) continue;
        ll b = N / a;
        ll cnt = 1;
        while (1){
            if (b < pow(10, cnt)) break;
            cnt++;
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}