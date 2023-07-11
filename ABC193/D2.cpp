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
    ull K;
    cin >> K;
    string S, T;
    cin >> S >> T;

    vector<ull> v(10);
    rep(i, 1, 10){
        int c = K;
        c -= count(S.begin(), S.end(), '0'+i);
        c -= count(T.begin(), T.end(), '0'+i);
        v[i] = c;
    }

    vector<vector<ull>> p(10, vector<ull>(10, 0));
    rep(i, 1, 10){
        ull x = v[i];
        rep(j, 1, 10){
            ull y = 0;
            if (i == j){
                y = v[j] - 1;
            }else{
                y = v[j];
            }
            p[i][j] = x * y;
            if (p[i][j]<=0) continue;
            ull s = 0;
            ull t = 0;
            rep(x, 1, 10){
                int cs = 0;
                int ct = 0;
                if (x == i) cs = 1;
                if (x == j) ct = 1;
                s += x * pow(10, count(S.begin(), S.end(), '0'+x) + cs);
                t += x * pow(10, count(T.begin(), T.end(), '0'+x) + ct);
            }
            if (s <= t){
                p[i][j] *= 0;
            }
        }
    }

    ull chi = 0;
    rep(i, 1, 10) rep(j, 1, 10){
        chi += p[i][j];
    }
    ull tot = (9*K-8) * (9*K-9);
    double ans = (double)chi / (double)tot;

    cout << ans << endl;

    return 0;
}