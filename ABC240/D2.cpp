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
    vector<vector<int>>g(n);
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n);
    int cnt = 0;
    vector<pair<int,int>>ans(n);
    function<int(int)> dfs = [&](int now){
        vis[now] = true;
        bool flag = true;
        int mi = cnt;
        int ma = cnt;
        for(auto nex: g[now]){
            if (vis[nex])continue;
            flag = false;
            int temp = dfs(nex);
            chmin(mi,temp);
            chmax(ma,temp);
        }
        ans[now] = {mi, ma};
        if (flag) cnt++;
        return cnt-1;
    };
    dfs(0);
    rep(i,0,n){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
    
    return 0;
}