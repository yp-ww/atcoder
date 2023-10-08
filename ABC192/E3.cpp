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
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    x--;y--;
    vector<vector<tuple<ll,ll,ll>>> g(n);
    rep(i,0,m){
        ll a,b,t,k;
        cin>>a>>b>>t>>k;
        a--;b--;
        g[a].push_back({b,t,k});
        g[b].push_back({a,t,k});
    }
    priority_queue<pair<ll,ll>> hq;
    hq.push({-0,x});
    vector<ll> v(n), ans(n, -1);
    while (!hq.empty()){
        auto [time, now] = hq.top(); hq.pop();
        time *= -1;
        if (v[now])continue;
        v[now] = true;
        ans[now] = time;
        if (now == y) break;
        for (auto [nex, cost, kk]: g[now]){
            if (v[nex]) continue;
            if (time%kk){
                hq.push({-(time+cost+kk-(time%kk)), nex});
            }else{
                hq.push({-(time+cost), nex});
            }
        }
    }
    cout << ans[y] << endl;

    return 0;
}