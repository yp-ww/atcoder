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

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>dis(n,vector<ll>(n,INF));
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        chmin(dis[a][b],c);
    }
    vector<vector<ll>>g(n);
    rep(i,0,n)rep(j,0,n){
        if (dis[i][j]!=INF) g[i].push_back(j);
    }
    rep(i,0,n){
        vector<ll> v(n,INF);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> hq;
        hq.push({0LL,i});
        ll ans = INF;
        while(!hq.empty()){
            auto [cost, now] = hq.top(); hq.pop();
            if (v[now]!=INF) continue;
            v[now] = cost;
            for (auto nex: g[now]){
                if (nex==i){
                    chmin(ans, v[now] + dis[now][nex]);
                }
                if (v[nex]!=INF)continue;
                hq.push({v[now]+dis[now][nex],nex});
            }
        }
        if (ans==INF)cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}