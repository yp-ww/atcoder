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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, 0, H) cin >> S[i];

    int INF = 100000;

    vector<int> dh = {0, 0, -1, 1};
    vector<int> dw = {-1, 1, 0, 0};

    auto bfs = [&](int sh, int sw, int th, int tw){
        if (S[sh][sw] == '#') return -INF;
        if (S[th][tw] == '#') return -INF;
        vector<int> d(H*W, -1);
        queue<pair<int, int>> q;
        q.push(make_pair(sh, sw));
        d[sh*W + sw] = 0;
        while (!q.empty()){
            auto now = q.front(); q.pop();
            int nowh = now.first;
            int noww = now.second;
            if (nowh == th && noww == tw){return d[nowh*W + noww];}
            rep(i, 0, 4){
                int nexh = nowh + dh[i];
                int nexw = noww + dw[i];
                if (0 <= nexh && nexh < H && 0 <= nexw && nexw < W){
                    if (S[nexh][nexw] == '#') continue;
                    if (d[nexh*W + nexw] != -1) continue;
                    d[nexh*W + nexw] = d[nowh*W + noww] + 1;
                    q.push(make_pair(nexh, nexw));
                }
            }
        }
        return -INF;
    };

    int ans = 0;
    rep(i, 0, H) rep(j, 0, W){
        rep(a, 0, H) rep(b, 0, W){
            if (i==a && j==b) continue;
            chmax(ans, bfs(i, j, a, b));
        }
    }

    cout << ans << endl;

    return 0;
}