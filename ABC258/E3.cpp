#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e18+10;

int main()
{
    ll n,q,x;
    cin>>n>>q>>x;
    vector<ll> w(n);
    rep(i,0,n)cin>>w[i];
    
    ll tot = 0;
    rep(i,0,n)tot+=w[i];

    // 何周するか
    ll rd = x/tot;
    ll rem = x%tot;

    vector<ll> nxt(n), cnt(n);
    ll r = 0;
    rep(l,0,n){ 
        while (rem >= 1){
            rem -= w[r%n];
            r++;
        }
        nxt[l] = r%n;
        cnt[l] = rd*n+r-l;
        if (l!=r) rem += w[l];
    }

    vector<vector<ll>> dp(60, vector<ll>(n));
    rep(i,0,n) dp[0][i] = nxt[i];
    rep(i,1,60)rep(j,0,n) dp[i][j] = dp[i-1][dp[i-1][j]];

    while(q){
        q--;
        ll k;
        cin>>k;
        ll now = 0;
        k--;
        rep(s,0,60){
            if (k&(1LL<<s)) now = dp[s][now];
        }
        cout << cnt[now] << endl;
    }

    return 0;
}