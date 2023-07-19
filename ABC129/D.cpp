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

    int ans = 0;
    vector<vector<int>> sw(H), sh(W);
    rep(i, 0, H) sw[i].push_back(-1);
    rep(j, 0, W) sh[j].push_back(-1);
    rep(i, 0, H) rep(j, 0, W){
        if (S[i][j] == '.') continue;
        sw[i].push_back(j);
        sh[j].push_back(i);
    }
    rep(i, 0, H) sw[i].push_back(W);
    rep(j, 0, W) sh[j].push_back(H);

    rep(i, 0, H) rep(j, 0, W){
        if (S[i][j] == '#') continue;
        auto itr = lower_bound(all(sw[i]), j);
        int wr = *itr;
        itr--;
        int wl = *itr;
        int dw = wr - (wl + 1);
        
        itr = lower_bound(all(sh[j]), i);
        int rh = *itr;
        itr--;
        int lh = *itr;
        int dh = rh - (lh + 1);
        chmax(ans, dw + dh - 1);
    }

    cout << ans << endl;

    return 0;
}