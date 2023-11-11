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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>>g(n);
    rep(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    queue<pair<ll,ll>> q;
    q.push({1,0LL});
    ll ans = k;
    while (!q.empty()){
        auto [s,cost] = q.front(); q.pop();
        if (s+1 == (1LL<<n)){
            chmin(ans, cost%k);
            continue;
        }
        rep(i,0,n){
            if (s&(1LL<<i)){
                ll now = i;
                for (auto [nex,w]: g[now]){
                    if (s&(1LL<<nex))continue;
                    ll snex = s;
                    snex |= 1LL<<now;
                    snex |= 1LL<<nex;
                    q.push({snex, (cost+w)%k});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}