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
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<ll> cum(n+1), score(n);
    rep(i,0,n){
        cum[i+1] = cum[i]+a[i];
    }
    rep(i,1,n){
        if (i%2){
            score[i] += cum[i/2+1];
            score[i] += cum[i/2];
        }else{
            score[i] += cum[i/2]*2;
        }
    }
    vector<ll> dp(n+1);
    rep(i,1,n+1){
        rep(j,1,n){
            if (i+j > n)break;
            chmax(dp[i+j], dp[i-1]+score[j]);
        }
    }
    cout << dp[n] << endl;

    return 0;
}