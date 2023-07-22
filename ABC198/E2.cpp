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

int main()
{
    int N;
    cin >> N;
    vector<int> C(N);
    rep(i, 0, N) cin >> C[i];
    vector<vector<int>> G(N);
    rep(i, 0, N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> ans;
    vector<bool> v(N);
    vector<int> cnt(100100, 0);
    function<void(int)> dfs = [&](int x){
        v[x] = true;
        if (cnt[C[x]] == 0) ans.push_back(x);
        cnt[C[x]] += 1;
        for (auto nex: G[x]){
            if (v[nex]) continue;
            dfs(nex);
        }
        cnt[C[x]] -= 1;
        return ;
    };

    dfs(0);

    sort(all(ans));
    for (auto p: ans){
        cout << p+1 << endl;
    }

    return 0;
}