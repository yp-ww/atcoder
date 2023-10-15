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
    vector<vector<ll>>g(n+1);
    rep(i,0,m){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll>v1(n+1,INF), vn(n+1,INF);
    queue<ll> q;
    q.push(1);
    v1[1] = 0;
    while (!q.empty()){
        ll now = q.front();q.pop();
        if (now == 0) continue;
        for (auto nex: g[now]){
            if (v1[nex]!=INF)continue;
            v1[nex] = v1[now] + 1;
            q.push(nex);
        }
    }
    q.push(n);
    vn[n] = 0;
    while (!q.empty()){
        ll now = q.front();q.pop();
        if (now == 0) continue;
        for (auto nex: g[now]){
            if (vn[nex]!=INF)continue;
            vn[nex] = vn[now] + 1;
            q.push(nex);
        }
    }

    rep(i,1,n+1){
        ll ans = v1[n];
        chmin(ans, v1[0]+vn[i]);
        chmin(ans, v1[i]+vn[0]);
        chmin(ans, v1[0]+vn[0]);
        if (ans == INF){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }

    return 0;
}