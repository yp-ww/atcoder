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

// a^b (mod m)
long long modpow(long long a, long long b, long long mod){
    long long res = 1;
    a %= mod;
    if (a == 0) return 0;
    while (b){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// nCk (mod m)
long long modcmb(long long n, long long k, long long mod){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    // O(k)
    long long res = 1;
    rep(i, n-k+1, n+1) res = res * i % mod;
    rep(i, 1, k+1) res = res * modpow(i, mod-2, mod) % mod;
    return res;
}

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;

    ll mod = (ll)1e9 + 7;
    ll ans = modpow(2, N, mod);
    ans -= 1;
    ans %= mod;

    ll a = modcmb(N, A, mod);
    ll b = modcmb(N, B, mod);
    ans -= a;
    ans %= mod;
    ans -= b;
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << endl;

    return 0;
}