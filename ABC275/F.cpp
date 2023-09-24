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


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    rep(i,0,n)cin>>a[i];
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(m+1, vector<ll>(2, INF)));

    dp[0][0][0] = 0;
    rep(i,0,n)rep(j,0,m+1)rep(k,0,2){
        if (dp[i][j][k] == INF) continue;
        if (k == 0){
            chmin(dp[i+1][j][1], dp[i][j][0] + 1);
            if (j+a[i]<=m) chmin(dp[i+1][j+a[i]][0], dp[i][j][0]);
        }else{
            chmin(dp[i+1][j][1], dp[i][j][1]);
            if (j+a[i]<=m) chmin(dp[i+1][j+a[i]][0], dp[i][j][1]);
        }
    }

    rep(i,1,m+1){
        ll ans = INF;
        chmin(ans, dp[n][i][0]);
        chmin(ans, dp[n][i][1]);
        if (ans == INF){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }

    return 0;
}