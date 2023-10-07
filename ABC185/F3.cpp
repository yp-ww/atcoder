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

ll op(ll a, ll b) { return a^b; };
ll e(){ return 0; };

int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    rep(i,0,n)cin>>a[i];
    segtree<ll,op,e> seg(n);
    rep(i,0,n){
        seg.set(i, a[i]);
    }
    rep(i,0,q){
        ll t,x,y;
        cin>>t>>x>>y;
        if (t==1){
            x--;
            seg.set(x, seg.get(x)^y);
        }else{
            x--;
            cout << seg.prod(x, y) << endl;
        }
    }
    return 0;
}