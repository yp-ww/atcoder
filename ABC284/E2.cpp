#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()

const double pi = 3.141592653589793;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

vector<bool> v(200200);
bool flag = false;
vector<vector<int>> G(200200);

int dfs(int now){
    v[now] = true;
    if (flag) return (int)1e6;

    int res = 1;
    for (auto nex: G[now]){
        if (v[nex]) continue;
        res += dfs(nex);
    }

    v[now] = false;
    chmin(res, (int)1e6);
    if (res == (int)1e6){
        flag = true;
    }
    return res;
}

int main()
{
    int N, M;
    cin >> N >> M;
    

    rep(i, 0, M){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout << dfs(0) << endl;
    
    return 0;
}