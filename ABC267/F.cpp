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
    int n;
    cin>>n;
    vector<vector<int>> g(n);
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> dis(n,-1);
    function<void(int,int)> dfs = [&](int now, int d){
        dis[now] = d;
        for (auto nex: g[now]){
            if (dis[nex]!=-1)continue;
            dfs(nex, d+1);
        }
        return ;
    };

    dfs(0, 0);
    int u = max_element(all(dis)) - dis.begin();
    
    vector<int> dis2(n,-1);
    function<void(int,int)> dfs2 = [&](int now, int d){
        dis2[now] = d;
        for (auto nex: g[now]){
            if (dis2[nex]!=-1)continue;
            dfs2(nex, d+1);
        }
        return ;
    };

    dfs2(u, 0);
    int v = max_element(all(dis2)) - dis2.begin();

    int q;
    cin>>q;
    vector<vector<pair<int,int>>> arr(n);
    rep(i,0,q){
        int x,k;
        cin>>x>>k;
        x--;
        arr[x].push_back({k,i});
    }

    vector<int> ans(q,-1);
    vector<int> dis3(n,-1);
    vector<queue<int>> qq(220000);
    function<void(int,int)> dfs3 = [&](int now, int d){
        dis3[now] = d;
        for (auto [k, idx]: arr[now]){
            if (k > d) continue;
            if (ans[idx] != -1) continue;
            qq[d-k].push(idx);
        }
        for (auto nex: g[now]){
            if (dis3[nex]!=-1)continue;
            dfs3(nex, d+1);
        }
        while (!qq[d].empty()){
            int idx = qq[d].front(); qq[d].pop();
            ans[idx] = now+1;
        }
        return ;
    };

    dfs3(u, 0);
    rep(i,0,n) dis3[i] = -1;
    dfs3(v, 0);
    
    rep(i,0,q){
        cout << ans[i] << endl;
    }

    return 0;
}