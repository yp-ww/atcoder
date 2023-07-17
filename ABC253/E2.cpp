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

using mint = modint998244353;

// a^b (mod m)
long long modpow(long long a, long long b, long long mod){
    long long res = 1;
    a %= mod;
    if (a == 0) return 0;
    while (b){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    if (K == 0){
        cout << modpow(M, N, 998244353);
        return 0;
    }

    vector<vector<mint>> dp(N+1, vector<mint>(M+1, 0));
    rep(j, 1, M+1) dp[0][j] = (mint)1;
    rep(i, 0, N){
        rep(j, 1, M+1){
            dp[i][j] += dp[i][j-1];
        }
        rep(j, 1, M+1){
            // j-K
            if (j-K > 0) dp[i+1][j] += dp[i][j-K];
            // j+K
            if (j+K <= M) dp[i+1][j] += dp[i][M] - dp[i][j+K-1];
        }
    }

    cout << dp[N-1][M].val() << endl;

    return 0;
}