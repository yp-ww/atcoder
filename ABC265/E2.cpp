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

mint dp[330][330][330] = {0};

int main()
{
    ll n,m;
    cin>>n>>m;
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;

    set<pair<ll,ll>> st;
    rep(i,0,m){
        ll x,y;
        cin>>x>>y;
        st.insert({x,y});
    }

    dp[0][0][0] = 1;
    rep(i,0,n)rep(j,0,n)rep(k,0,n){
        if (dp[0][0][0] == 0) continue;
        if (i+j+k>n)continue;
        ll nowx = a*i+c*j+e*k;
        ll nowy = b*i+d*j+f*k;
        if (st.find({nowx+a,nowy+b}) == st.end()){
            dp[i+1][j][k] += dp[i][j][k];
        }
        if (st.find({nowx+c,nowy+d}) == st.end()){
            dp[i][j+1][k] += dp[i][j][k];
        }
        if (st.find({nowx+e,nowy+f}) == st.end()){
            dp[i][j][k+1] += dp[i][j][k];
        }
    }

    mint ans = 0;
    rep(i,0,n+1)rep(j,0,n+1)rep(k,0,n+1){
        if (i+j+k>n)continue;
        if ((i+j+k)!=n) continue;
        ans += dp[i][j][k];
    }
    cout << ans.val() << endl;

    return 0;
}