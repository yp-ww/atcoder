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
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N), C(Q+2, 1);
    rep(i, 0, N) cin >> A[i];
    rep(i, 1, Q+1) cin >> C[i];
    ll MOD = 1000000007;

    vector<mint> cum(N+1);
    rep(i, 0, N){
        cum[i+1] = cum[i] + modpow(A[i], A[i+1], MOD);
    }

    mint ans = 0;
    rep(i, 0, Q+1){
        ll a = C[i];
        ll b = C[i+1];
        if (a > b) swap(a, b);
        ans += cum[b-1] - cum[a-1];
    }
    cout << ans.val() << endl;

    return 0;
}