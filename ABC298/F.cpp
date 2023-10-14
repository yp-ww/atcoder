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

ll op(ll a, ll b){ return max(a, b); };
ll e(){ return 0; };

int main()
{
    ll n;
    cin>>n;
    
    map<ll,ll> mpr, mpc;
    vector<vector<tuple<ll,ll,ll>>> arr(n);
    segtree<ll,op,e> seg(n);
    vector<ll> cumr(n);
    rep(i,0,n){
        ll r,c,x;
        cin>>r>>c>>x;
        if (mpr.find(r)==mpr.end()) mpr[r] = i;
        if (mpc.find(c)==mpc.end()) mpc[c] = i;
        arr[mpr[r]].push_back({r,c,x});
        cumr[mpr[r]] += x;
        seg.set(mpc[c], seg.get(mpc[c])+x);
    }

    ll ans = 0;
    rep(i,0,n){
        if (arr[i].size() == 0) continue;
        for (auto [r,c,x]: arr[i]){
            seg.set(mpc[c], seg.get(mpc[c])-x);
        }
        chmax(ans, cumr[i]+seg.all_prod());
        for (auto [r,c,x]: arr[i]){
            seg.set(mpc[c], seg.get(mpc[c])+x);
        }
    }
    cout << ans << endl;

    return 0;
}