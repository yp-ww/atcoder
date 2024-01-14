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

using mint = modint1000000007;

int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<mint>> dp(8, vector<mint>(n+1));
    dp[0][0] = 1;
    string t = "atcoder";
    vector<ll> cnt(26);
    rep(i,0,7) cnt[t[i]-'a'] = i+1; 
    rep(j,1,n+1)rep(i,0,8){
        if (i==0){
            dp[i][j] = dp[i][j-1];
            continue;
        }
        if (cnt[s[j-1]-'a'] == i){
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
        }else{
            dp[i][j] = dp[i][j-1];
        }
    }
    cout << dp[7][n].val() << endl;

    return 0;
}