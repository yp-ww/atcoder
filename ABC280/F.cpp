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
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<pair<ll,ll>>> g(n);
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        g[a].push_back({b,c});
        g[b].push_back({a,-c});
    }

    vector<pair<ll,ll>> v(n,{-INF,INF});
    vector<bool> ng(n);
    function<void(ll,ll,ll,ll)> dfs = [&](ll now, ll pre, ll tot, ll par){
        v[now] = {tot, par};
        for (auto [nex, cost]: g[now]){
            if (v[nex].first != -INF){
                if (v[nex].first != v[now].first+cost){
                    ng[par] = true;
                }
                continue;
            }
            dfs(nex, now, tot+cost, par);
        }
        return ;
    };

    rep(i,0,n){
        if (v[i].first != -INF) continue;
        dfs(i,-1,0,i);
    }

    rep(i,0,q){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        if (v[x].second!=v[y].second){
            cout << "nan" << endl;
        }else{
            if (ng[v[x].second]){
                cout << "inf" << endl;
            }else{
                cout << v[y].first-v[x].first << endl;
            }
        }
    }


    return 0;
}