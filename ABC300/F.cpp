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
    ll n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;

    ll cnt=0;
    rep(i,0,n){
        if (s[i]=='x') cnt++;
    }
    
    vector<ll> cum(n+1,0);
    rep(i,0,n){
        cum[i+1] = cum[i];
        if (s[i]=='x') cum[i+1]++;
    }

    auto f = [&](ll x){
        ll res = (x/n) * cum[n];
        ll rem = x%n;
        res += cum[rem];
        return res;
    };

    ll ans = 0;
    rep(i,0,n){
        ll l = i;
        ll r = n*m+1;
        while(r-l>1){
            ll mid = (l+r)/2;
            if (f(mid)-cum[i]<=k){
                l = mid;
            }else{
                r = mid;
            }
        }
        chmax(ans, l-i);
    }
    cout << ans << endl;
    
    return 0;
}