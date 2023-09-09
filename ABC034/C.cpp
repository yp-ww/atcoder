#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e15;

using mint = modint1000000007;

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

int main()
{
    int W, H;
    cin >> W >> H;
    ll MOD = 1000000007;
    mint ans = 1;
    rep(i, 1, H+W-1){
        ans *= i;
    }
    rep(i, 1, H){
        ans *= modpow(i, MOD-2, MOD);
    }
    rep(i, 1, W){
        ans *= modpow(i, MOD-2, MOD);
    }
    cout << ans.val() << endl;

    return 0;
}