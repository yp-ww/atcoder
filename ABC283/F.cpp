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

ll op(ll a, ll b){ return min(a, b); };
ll e(){ return INF; };

int main()
{
    int n;
    cin >> n;
    vector<int>p(n+1);
    rep(i,1,n+1)cin>>p[i];

    segtree<ll,op,e> seg1(n+1), seg2(n+1), seg3(n+1), seg4(n+1);
    rep(i,1,n+1){
        seg1.set(p[i], p[i]+i);
        seg2.set(p[i], i-p[i]);
    }
    vector<ll> ans(n+1);
    rep(i,1,n+1){
        ll res = INF;
        seg1.set(p[i], INF);
        seg2.set(p[i], INF);
        chmin(res, -(p[i]+i) + seg1.prod(p[i]+1, n+1));
        chmin(res, p[i]-i + seg2.prod(0, p[i]));
        chmin(res, -p[i]+i + seg3.prod(p[i]+1, n+1));
        chmin(res, p[i]+i + seg4.prod(0, p[i]));
        seg3.set(p[i], p[i]-i);
        seg4.set(p[i], -p[i]-i);
        ans[i] = res;
    }
    rep(i,1,n+1){
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}