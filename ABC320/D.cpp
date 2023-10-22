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
const ll INF = (ll)3e15;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<tuple<ll,ll,ll>>> g(n);
    rep(i,0,m){
        ll a,b,x,y;
        cin>>a>>b>>x>>y;
        a--;b--;
        g[a].push_back({b,x,y});
        g[b].push_back({a,-x,-y});
    }
    queue<ll> q;
    q.push(0);
    vector<bool> v(n);
    vector<pair<ll,ll>> xy(n, {INF,INF});
    xy[0] = {0,0};
    v[0] = true;
    while (!q.empty()){
        ll now = q.front(); q.pop();
        auto [x,y] = xy[now];
        for (auto [nex,dx,dy]: g[now]){
            if (v[nex])continue;
            v[nex]=true;
            xy[nex] = {x+dx,y+dy};
            q.push(nex);
        }
    }
    rep(i,0,n){
        auto [x,y] = xy[i];
        if (x==INF){
            cout << "undecidable" << endl;
        }else{
            cout << x << " " << y << endl;
        }
    }

    return 0;
}