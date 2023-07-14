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
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<vector<int>> G(N, vector<int>());
    vector<ll> dp(N, 1e15);
    vector<int> indeg(N, 0);
    
    rep(i, 0, M){
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        indeg[y] += 1;
    }

    queue<int> q;
    rep(i, 0, N){
        if (indeg[i]) continue;
        q.push(i);
    }

    while (!q.empty()){
        int now = q.front();q.pop();
        for (auto nex: G[now]){
            chmin(dp[nex], A[now]);
            chmin(dp[nex], dp[now]);
            indeg[nex] -= 1;
            if (!indeg[nex]) q.push(nex);
        }
    }

    ll ans = -1e15;
    rep(i, 0, N) chmax(ans, A[i] - dp[i]);

    cout << ans << endl;

    return 0;
}