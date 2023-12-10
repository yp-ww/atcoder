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

using mint = modint998244353;

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> g(n);
    rep(i,0,m){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,0,n)g[i].push_back(i);
    vector<vector<mint>> dp(k+1,vector<mint>(n));
    dp[0][0] = 1;
    rep(i,1,k+1){
        mint tot = 0;
        rep(j,0,n) tot += dp[i-1][j];
        rep(j,0,n) dp[i][j] = tot;
        rep(now,0,n){
            for (auto nex: g[now]){
                dp[i][nex] -= dp[i-1][now];
            }
        }
    }
    cout << dp[k][0].val() << endl;
    
    return 0;
}