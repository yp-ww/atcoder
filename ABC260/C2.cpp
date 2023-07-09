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
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> red(N+1, 0), blue(N+1, 0);
    red[N] = 1;
    rrep(i, N, 2){
        red[i-1] += red[i];
        blue[i] += red[i] * X;
        red[i-1] += blue[i];
        blue[i-1] += blue[i] * Y;
    }
    cout << blue[1] << endl;

    return 0;
}