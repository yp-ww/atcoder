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
const ll INF = (ll)1e15;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    vector<vector<ll>> dp(n+1, vector<ll>(m+1,INF));
    rep(i,1,n+1) dp[i][0] = i;
    rep(i,1,m+1) dp[0][i] = i;
    dp[0][0] = 0;
    rep(i,1,n+1)rep(j,1,m+1){
        if (a[i-1] == b[j-1]){
            chmin(dp[i][j], dp[i-1][j-1]);
        }
        chmin(dp[i][j], dp[i-1][j-1]+1);
        chmin(dp[i][j], dp[i-1][j]+1);
        chmin(dp[i][j], dp[i][j-1]+1);
    }
    cout << dp[n][m] << endl;
    return 0;
}