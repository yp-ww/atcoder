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

    int ans = 4;
    rep(i, 1, H-1) rep(j, 1, W-1){
        if (S[i][j] == '#') continue;
        if (S[i-1][j] == '#' && S[i][j-1] == '#') ans += 2;
        if (S[i-1][j] == '#' && S[i][j+1] == '#') ans += 2;
        if (S[i+1][j] == '#' && S[i][j-1] == '#') ans += 2;
        if (S[i+1][j] == '#' && S[i][j+1] == '#') ans += 2;
    }
    cout << ans << endl;
    return 0;
}