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
    ll n,q,x;
    cin>>n>>q>>x;
    vector<ll> w(n);
    rep(i,0,n)cin>>w[i];
    
    ll tot = 0;
    rep(i,0,n)tot+=w[i];

    // 何周するか
    ll rd = x/tot;
    ll rem = x%tot;
    
    vector<ll> a(n);
    ll na = rd*n;
    rep(i,0,n){    
        while (rem >= 1){
            rem -= w[(i+na)%n];
            na++;
        }
        a[i] = na;
        rem += w[i];
        na--;
    }

    vector<vector<ll>> dp(60, vector<ll>(n));
    rep(i,0,n){
        dp[0][i] = (i+a[i])%n;
    }

    rep(i,1,60) rep(j,0,n){
        dp[i][j] = dp[i-1][dp[i-1][j]];
    }

    rep(_,0,q){
        ll k;
        cin>>k;
        int si = 0;
        k--;
        rep(i,0,60){
            if ((k>>i)&1){
                si = dp[i][si];
            }
        }
        cout << a[si] << endl;
    
    }
    

}