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
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> g(n);
    vector<bool> te(n);
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        u--;v--;
        if (u == -1){
            te[v] = true;
        }else{
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    int inf = 1000000010;
    vector<int> to(n,inf), ba(n,inf);
    queue<int> q;
    q.push(0);
    to[0] = 0;
    while (!q.empty()){
        int now = q.front(); q.pop();
        for (auto nex: g[now]){
            if (to[nex]!=inf) continue;
            to[nex] = to[now] + 1;
            q.push(nex);
        }
    }
    
    q.push(n-1);
    ba[n-1] = 0;
    while (!q.empty()){
        int now = q.front(); q.pop();
        for (auto nex: g[now]){
            if (ba[nex]!=inf) continue;
            ba[nex] = ba[now] + 1;
            q.push(nex);
        }
    }

    int st = -1;
    int temp = inf;
    rep(i,0,n){
        if (!te[i]) continue;
        if (temp >= to[i]){
            st = i;
            temp = to[i];
        }
    }
    int go = -1;
    temp = inf;

    rrep(i,n-1,0){
        if (!te[i]) continue;
        if (temp >= ba[i]){
            go = i;
            temp = ba[i];
        }
    }

    rep(i,0,n){
        ll ans = to[n-1];
        if (st!=-1) chmin(ans, (ll)to[st]+(ll)ba[i]+1);
        if (go!=-1) chmin(ans, (ll)ba[go]+(ll)to[i]+1);
        if (st!=-1&&go!=-1) chmin(ans, (ll)to[st]+(ll)ba[go]+2);
        if (ans >= inf){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }
    
    return 0;
}