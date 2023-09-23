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

ll op(ll a, ll b){ return gcd(a, b); }
ll e(){ return 0LL; }

int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];

    segtree<ll,op,e> sega(n), segb(n);
    sega.set(0, a[0]);
    segb.set(0, b[0]);
    rep(i,1,n){
        sega.set(i, a[i]-a[i-1]);
        segb.set(i, b[i]-b[i-1]);
    }

    rep(i,0,q){
        int h1,h2,w1,w2;
        cin>>h1>>h2>>w1>>w2;
        h1--;h2--;w1--;w2--;

        ll ans = a[h1]+b[w1];
        if (h1 != h2) ans = gcd(ans, sega.prod(h1+1,h2+1));
        if (w1 != w2) ans = gcd(ans, segb.prod(w1+1,w2+1));
        
        cout << ans << endl;
    }


    return 0;
}