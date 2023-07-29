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
const ll INF = (ll)1e15;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<int> indeg(N);
    rep(i, 0, N-1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        indeg[u]++;
        indeg[v]++;
    }

    vector<bool> v(N);
    queue<int> q;
    rep(i, 0, N){
        if (indeg[i] == 1) q.push(i);
    }

    vector<int> ans;
    while (!q.empty()){
        int now = q.front(); q.pop();
        if (v[now]) continue;
        int nex = 0;
        for (auto pos: G[now]){
            if (v[pos]) continue;
            nex = pos; break;                 
        }

        ans.push_back(indeg[nex]);
        v[nex] = true;
        for (auto pos: G[nex]){
            if (v[pos]) continue;
            indeg[nex]--;
            indeg[pos]--;
            v[pos] = true;
            for (auto nnex: G[pos]){
                if (v[nnex]) continue;
                if (indeg[nnex]) q.push(nnex);
            }
        }
    }

    sort(all(ans));
    rep(i, 0, ans.size()){
        cout << ans[i] << " ";
    }

    return 0;
}