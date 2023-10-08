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
    ll n,m;
    cin>>n>>m;
    vector<ll>p(n),l(m),d(m);
    rep(i,0,n)cin>>p[i];
    rep(i,0,m)cin>>l[i];
    rep(i,0,m)cin>>d[i];
    sort(all(p));
    vector<vector<ll>> arr(n+1);
    priority_queue<ll> hq;
    rep(i,0,m){
        ll idx = lower_bound(all(p), l[i]) - p.begin();
        arr[idx].push_back(d[i]);
    }
    ll ans = 0;
    rep(i,0,n){
        for (auto x: arr[i]){
            hq.push(x);
        }
        ans += p[i];
        if (!hq.empty()){
            ll now = hq.top(); hq.pop();
            ans -= now;
        }
    }
    cout << ans << endl;
    return 0;
}