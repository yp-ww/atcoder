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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> cnt(N, 0);
    X--; Y--;
    rep(i, 0, N) rep(j, i+1, N){
        int dis = min(j - i, abs(X-i) + abs(Y-j) + 1);
        cnt[dis] += 1;
    }

    rep(i, 1, N){
        cout << cnt[i] << endl;
    }  

    return 0;
}