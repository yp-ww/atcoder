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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    rep(i, 0, M){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> v(N);
    queue<int> q;
    vector<pair<int,int>> t2;
    q.push(0);
    v[0] = 1;
    while (!q.empty()){
        int now = q.front(); q.pop();
        for (auto nex: G[now]){
            if (v[nex]) continue;
            v[nex] = 1;
            q.push(nex);
            t2.push_back({now, nex});
        }
    }

    rep(i, 0, N) v[i] = 0;
    vector<pair<int,int>> t1;
    function<void(int)> dfs = [&](int now){
        v[now] = 1;
        for (auto nex: G[now]){
            if (v[nex]) continue;
            t1.push_back({now, nex});
            dfs(nex);
        }
        return ;
    };
    dfs(0);

    for (auto p: t1){
        cout << p.first+1 << " ";
        cout << p.second+1 << endl;
    }
    for (auto p: t2){
        cout << p.first+1 << " ";
        cout << p.second+1 << endl;
    }    

    return 0;
}