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
    vector<int> T(N);
    rep(i, 0, N) cin >> T[i];

    int tot = accumulate(all(T), 0);
    int MAX = 100100;
    vector<vector<bool>> dp(N+1, vector<bool>(MAX+1, 0));
    dp[0][0] = true;
    rep(i, 0, N) rep(j, 0, MAX){
        if (!dp[i][j]) continue;
        dp[i+1][j] = true;
        if (j+1<MAX) dp[i+1][j+T[i]] = true;
    }

    int ans = (int)1e8;
    rep(j, 0, 100000+1){
        if (!dp[N][j]) continue;
        int temp = abs(tot - j);
        chmax(temp, j);
        chmin(ans, temp);
    }
    
    cout << ans << endl;

    return 0;
}