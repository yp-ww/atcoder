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

void solve(){
    ll n,x,k;
    cin>>n>>x>>k;
    ll xd = 0;
    while (x >> xd) xd++;
    
    auto f = [&](ll now, ll kk, ll depth){
        if (depth+kk > 60) return 0LL;
        ll l = now << kk;
        if (n < l) return 0LL;
        ll r = ((now+1) << kk) - 1;
        chmin(r, n);
        return r-l+1;
    };

    ll ans = 0;
    rep(i,0,k+1){
        if ((x>>i) == 0) break;
        ans += f(x>>i, k-i, xd-i);
        if (i-1>=0 && k-i-1>=0) ans -= f(x>>(i-1), k-i-1, xd-i+1);       
    }
    
    cout << ans << endl;
}

int main()
{
    ll t;
    cin>>t;
    
    while (t){
        t--;
        solve();
    }

    return 0;
}