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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(m),b(m),c(m);
    rep(i,0,m){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;b[i]--;
    }
    vector<ll> e(k);
    rep(i,0,k)cin>>e[i];
    rep(i,0,k)e[i]--;
    vector<ll> v(n, INF);
    v[0] = 0;
    rep(i,0,k){
        ll p = e[i];
        ll now = a[p];
        ll nex = b[p];
        ll cost = c[p];
        chmin(v[nex], v[now]+cost);    
    }
    if (v[n-1]==INF){
        cout << -1 << endl;
    }else{
        cout << v[n-1] << endl;
    }

    return 0;
}