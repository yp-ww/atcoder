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
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)a[i]--;
    
    scc_graph g(n);
    int ans = 0;
    rep(i,0,n){
        if (i==a[i])ans++;
        g.add_edge(i, a[i]);
    }
    auto scc = g.scc();

    vector<int> ok;
    for (auto s: scc){
        int sz = s.size();
        if (sz<=1) continue;
        for (auto x: s) ok.push_back(x);
    }

    vector<bool>v(n);
    for(auto x: ok) v[a[x]] = true;
    rep(i,0,n)if(v[i])ans++;
    cout << ans << endl;

    return 0;
}