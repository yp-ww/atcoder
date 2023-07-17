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

    vector<vector<int>> A(H, vector<int>(W, 0));
    rep(i, 0, H) rep(j, 0, W) cin >> A[i][j];

    vector<tuple<int, int, int, int>> v;
    rep(i, 0, H) rep(j, 0, W){
        if (A[i][j] % 2 == 0) continue;
        if (j+1 < W){
            A[i][j] -= 1;
            A[i][j+1] += 1;
            v.push_back(make_tuple(i+1, j+1, i+1, j+2));
        }
    }

    rep(i, 0, H){
        if (A[i][W-1] % 2 == 0) continue;
        if (i+1 < H){
            A[i][W-1] -= 1;
            A[i+1][W-1] += 1;
            v.push_back(make_tuple(i+1, W, i+2, W));
        }
    }

    cout << v.size() << endl;
    for (auto t: v){
        int y1 = get<0>(t);
        int x1 = get<1>(t);
        int y2 = get<2>(t);
        int x2 = get<3>(t);
        cout << y1 << " " << x1 << " " << y2 << " " << x2 << endl;
    }

    return 0;
}