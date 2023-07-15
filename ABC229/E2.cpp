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
    vector<vector<int>> G(N, vector<int>());
    rep(i, 0, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }

    dsu d(N);
    vector<int> ans(N+1);
    int cnt = 0;
    rrep(i, N-1, 0){
        cnt++;
        for (auto nex: G[i]){
            if (!d.same(i, nex)){
                cnt--;
                d.merge(nex, i);
            }
        }
        ans[i] = cnt;
    }

    rep(i, 1, N+1) cout << ans[i] << endl;

    return 0;
}