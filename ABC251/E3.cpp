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
    vector<ll> dp(n+10, INF);
    dp[0] = a[0];
    dp[1] = a[0];
    rep(i,1,n){
        chmin(dp[i], dp[i-1]+a[i]);
        chmin(dp[i+1], dp[i-1]+a[i]);
    }
    vector<ll> dp2(n+10, INF);
    dp2[0] = a[n-1];
    dp2[n-1] = a[n-1];
    rep(i,0,n-1){
        chmin(dp2[i], dp2[(i-1+n)%n]+a[i]);
        chmin(dp2[i+1], dp2[(i-1+n)%n]+a[i]);
    }
    cout << min(dp[n-1], dp2[n-2]);

    return 0;
}