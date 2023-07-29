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
    vector<vector<int>> G(N);
    rep(i, 0, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    priority_queue<pair<int, int>> hq;
    vector<int> v(N);
    rep(i, 0, K){
        int p, h;
        cin >> p >> h;
        p--;
        hq.push({h+1, p});
    }

    while (!hq.empty()){
        auto p = hq.top(); hq.pop();
        int now = p.second;
        int h = p.first;
        if (v[now]) continue;
        v[now] = h;
        if (v[now] <= 1) continue;
        for (auto nex: G[now]){
            if (v[nex]) continue;
            hq.push({h-1, nex});
        }
    }

    vector<int> ans;
    rep(i, 0, N){
        if (v[i]) ans.push_back(i+1); 
    }
    cout << ans.size() << endl;
    rep(i, 0, ans.size()){
        cout << ans[i] << " ";
    }
    return 0;
}