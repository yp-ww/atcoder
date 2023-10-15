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

using mint = modint998244353;

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    mint ans = 0;
    rep(k,1,n+1){
        vector<ll>b(n);
        rep(i,0,n){
            b[i] = a[i]%k;
        }
        vector<vector<vector<mint>>> dp(n+1, vector<vector<mint>>(k, vector<mint>(k+1)));
        dp[0][0][0] = 1;
        rep(i,0,n)rep(j,0,k)rep(l,0,k+1){
            if (dp[i][j][l] == 0)continue;
            dp[i+1][j][l] += dp[i][j][l];
            if (l<k) dp[i+1][(j+b[i])%k][l+1] += dp[i][j][l];
        }
        ans += dp[n][0][k];
    }
    cout << ans.val() << endl;
    return 0;
}