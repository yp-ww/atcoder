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
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> G(2*N);
    rep(i, 0, M){
        int u, v, a;
        cin >> u >> v >> a;
        u--; v--;
        if (a){
            G[u].push_back(make_pair(v, 1));
            G[v].push_back(make_pair(u, 1));            
        }else{
            G[u+N].push_back(make_pair(v+N, 1));
            G[v+N].push_back(make_pair(u+N, 1));            
        }       
    }
    rep(i, 0, K){
        int u;
        cin >> u;
        u--;
        G[u].push_back(make_pair(u+N, 0));
        G[u+N].push_back(make_pair(u, 0));  
    }

    int INF = 10001000;
    vector<int> d(2*N, INF);
    d[0] = 0;
    deque<int> q;
    q.push_back(0);

    while (!q.empty()){
        int now = q.front(); q.pop_front();
        for (auto p: G[now]){
            int nex = p.first;
            int cost = p.second;
            if (d[nex] != INF) continue;
            d[nex] = d[now] + cost;
            if (cost){
                q.push_back(nex);
            }else{
                q.push_front(nex);
            }
        }
    }

    int ans = min(d[N-1], d[2*N-1]);
    if (ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    
    return 0;
}