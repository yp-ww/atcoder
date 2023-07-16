#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> indeg(N, 0);
    int ans = N;
    vector<set<int>> G(N, set<int>{});

    rep(i, 0, Q){
        int q;
        cin >> q;
        if (q == 1){
            int u, v;
            cin >> u >> v;
            u--; v--;
            if (!indeg[u]) ans--;
            if (!indeg[v]) ans--;
            indeg[u]++;
            indeg[v]++;
            G[u].insert(v);
            G[v].insert(u);
            cout << ans << endl;
        }else{
            int v;
            cin >> v;
            v--;
            for (auto itr = G[v].begin(); itr != G[v].end(); itr++){
                int u = *itr;
                indeg[u]--;
                indeg[v]--;
                if (!indeg[u]) ans++;
                G[u].erase(v);
                if (!indeg[v]) ans++;
            }
            G[v] = {};
            cout << ans << endl;
        }
    }


    return 0;
}