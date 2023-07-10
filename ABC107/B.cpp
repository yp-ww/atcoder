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
    int H, W;
    cin >> H >> W;
    vector<string> G(H);
    rep(i, 0, H) cin >> G[i];

    set<int> ngh, ngw;
    rep(i, 0, H){
        bool flag = true;
        rep(j, 0, W){
            if (G[i][j] == '#') flag = false;
        }
        if (flag) ngh.insert(i);
    }

    rep(j, 0, W){
        bool flag = true;
        rep(i, 0, H){
            if (G[i][j] == '#') flag = false;
        }
        if (flag) ngw.insert(j);
    }

    rep(i, 0, H){
        if (ngh.find(i) != ngh.end()) continue;
        rep(j, 0, W){
            if (ngw.find(j) != ngw.end()) continue;
            cout << G[i][j];
        }
        cout << endl;
    }

    return 0;
}