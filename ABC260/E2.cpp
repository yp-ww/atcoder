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
const ll INF = (ll)1e18+10;

ll op1(ll a, ll b){ return max(a,b); };
ll e1(){ return 0LL; };
ll op2(ll a, ll b){ return min(a,b); };
ll e2(){ return INF; };

int main()
{
    int n,m;
    cin>>n>>m;
    segtree<ll,op1,e1> seg1(m+1);
    segtree<ll,op2,e2> seg2(m+1);

    rep(i,0,n){
        ll a,b;
        cin>>a>>b;
        ll now = seg1.get(a);
        if (now < b) seg1.set(a, b);
        now = seg2.get(a);
        if (now > b) seg2.set(a, b);
    }

    vector<ll> ans(m+2);
    rep(i,1,m+1){
        ll ng = i-1;
        ll ok = m+1;
        while (ok-ng>1){
            ll mid = (ng+ok)/2;
            ll rmax = seg1.prod(mid+1, m+1);     
            ll lmax = seg1.prod(0,i);
            ll lmin = seg2.prod(0,i);
            bool flag = true;
            if (lmin < i) flag = false;
            if (lmax > mid) flag = false;
            if (rmax > mid) flag = false;
            if (flag){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        if (ng==m) continue;
        ans[ok-i+1]++;
        ans[m-i+2]--;
    }

    rep(i,1,m+1) ans[i] += ans[i-1];
    rep(i,1,m+1) cout << ans[i] << endl;
    
    return 0;
}