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

using mint = modint1000000007;
mint dp[2020][2020] = {0};
mint cum[2020][2020][3] = {0};
int main()
{
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,0,h)cin>>s[i];
    dp[0][0] = 1;
    rep(i,0,h)rep(j,0,w){
        if (s[i][j] == '#') continue;
        if (j-1>=0) cum[i][j][0] += cum[i][j-1][0];
        if (i-1>=0) cum[i][j][1] += cum[i-1][j][1];
        if (i-1>=0&&j-1>=0) cum[i][j][2] += cum[i-1][j-1][2];
        cum[i][j][0] += dp[i][j];
        cum[i][j][1] += dp[i][j];
        cum[i][j][2] += dp[i][j];
        if (j+1<w && s[i][j+1] != '#'){
            dp[i][j+1] += cum[i][j][0];
        }
        if (i+1<h && s[i+1][j] != '#'){
            dp[i+1][j] += cum[i][j][1];
        }
        if (i+1<h && j+1<w && s[i][j] != '#'){
            dp[i+1][j+1] += cum[i][j][2];
        }
    }
    cout << dp[h-1][w-1].val() << endl;

    return 0;
}