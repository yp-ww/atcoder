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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n;
    cin>>n;
    vector<ll>indeg(n);
    vector<vector<ll>>g(n);
    rep(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        indeg[u]++;
        indeg[v]++;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    vector<ll>ans, v(n,0);
    rep(i,0,n){
        if (v[i]) continue;
        if (indeg[i]>=3){
            ans.push_back(indeg[i]);
            v[i] = true;
            for (auto nex: g[i]){
                v[nex] = true;
            }
        }
    }
    ll cnt = 0;
    rep(i,0,n){
        if (!v[i]) cnt++;
    }
    ll sz = cnt/3;
    rep(i,0,sz)ans.push_back(2);

    sort(all(ans));
    // cout << ans.size() << endl;
    for (auto x: ans) cout << x << endl;

    return 0;
}