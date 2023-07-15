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
    vector<int> P(N);
    vector<vector<int>> G(N, vector<int>());
    rep(i, 1, N){
        int p;
        cin >> p;
        p--;
        G[p].push_back(i);
    }

    vector<int> dp(N, 0);
    rep(i, 0, M){
        int x, y;
        cin >> x >> y;
        x--;
        y++;
        chmax(dp[x], y);
    }

    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int now = q.front();q.pop();
        for (auto nex: G[now]){
            chmax(dp[nex], dp[now]-1);
            q.push(nex);
        }
    }

    int ans = N - count(dp.begin(), dp.end(), 0);
    cout << ans << endl;

    return 0;
}