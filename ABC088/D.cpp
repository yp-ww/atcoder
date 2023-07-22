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

    vector<vector<int>> v(H, vector<int>(W, -1));
    queue<pair<int, int>> q;
    v[0][0] = 0;
    q.push(make_pair(0, 0));

    vector<int> dh = {0, 0, -1, 1};
    vector<int> dw = {-1, 1, 0, 0};

    while (!q.empty()){
        auto p = q.front(); q.pop();
        auto h = p.first;
        auto w = p.second;
        rep(i, 0, 4){
            int nh = h + dh[i];
            int nw = w + dw[i];
            if (!(0 <= nh && nh < H && 0 <= nw && nw < W)) continue;
            if (S[nh][nw] == '#') continue;
            if (v[nh][nw] != -1) continue;
            v[nh][nw] = v[h][w] + 1;
            q.push(make_pair(nh, nw));
        }
    }

    if (v[H-1][W-1] == -1){
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    rep(i, 0, H) rep(j, 0, W){
        if (S[i][j] == '#') cnt++;
    }

    int d = v[H-1][W-1] + 1;
    int ans = H * W;
    ans -= cnt;
    ans -= d;

    cout << ans << endl;
    

    return 0;
}