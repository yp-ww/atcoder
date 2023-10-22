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
const ll INF = (ll)3e15;

int main()
{
    ll n,d,p;
    cin>>n>>d>>p;
    vector<ll>f(n);
    rep(i,0,n)cin>>f[i];
    ll ans = INF;
    sort(all(f), greater());
    vector<ll>cum(n+1);
    rep(i,0,n)cum[i+1] = cum[i] + f[i];
    ll cnt = -1;
    while (cnt*d<=n){
        cnt++;
        ll use = cnt*d;
        ll cost = cnt*p;
        cost += cum[n] - cum[min(n,use)];
        chmin(ans, cost);        
    }
    cout << ans << endl;

    return 0;
}