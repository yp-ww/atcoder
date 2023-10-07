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

using mint = modint998244353;

mint dp[10010][1010] = {0};

int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>t(n+1);
    rep(i,1,n+1)cin>>t[i];
    dp[0][0] = (mint)1/(mint)n;
    rep(i,0,x+1){
        rep(j,1,n+1){
            dp[i][j] += dp[i][0];
        }
        rep(j,1,n+1){
            if (dp[i][j]==0) continue;
            if (i+t[j]<=x) dp[i+t[j]][0] += dp[i][j]/(mint)n;
        }
    }
    mint ans = 0;
    rep(i,0,t[1]){
        if (x-i<0) break;
        ans += dp[x-i][1];
    }
    cout << ans.val() << endl;

    return 0;
}