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
    ll n;
    cin>>n;
    vector<vector<ll>>g(n);
    vector<ll>indeg(n);
    rep(i,0,n){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        indeg[u]++;
        indeg[v]++;
    }

    vector<bool> v(n);
    vector<bool> cir(n);
    int pos = -1;
    function<bool(int,int)> dfs = [&](int now, int pre){
        v[now] = true;
        bool flag = false;
        for (auto nex: g[now]){
            if (nex == pre) continue;
            if (v[nex] && pos == -1){
                pos = nex;
                flag = true;
                continue; 
            }
            if (v[nex])continue;
            flag |= dfs(nex, now);
        }
        if (flag) cir[now] = true;
        if (now == pos) flag = false;
        return flag;
    };

    dfs(0, -1);
    dsu uf(n);
    vector<bool> ch(n);
    rep(i,0,n){
        if (indeg[i] > 1) continue;
        if (ch[i]) continue;
        queue<int> q;
        q.push(i);
        while (!q.empty()){
            int now = q.front(); q.pop();
            if (cir[now]) continue;
            for (auto nex: g[now]){
                if (ch[nex]){
                    uf.merge(i,nex);
                    continue;
                }
                uf.merge(i, nex);
                ch[nex] = true;
                q.push(nex);
            }
        }
    }
    ll q;
    cin>>q;
    rep(i,0,q){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        YesNo(uf.same(x,y));
    }

    return 0;
}
