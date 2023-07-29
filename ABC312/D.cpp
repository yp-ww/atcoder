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
const ll INF = (ll)1e15;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

using mint = modint998244353;

int main()
{
    string S;
    cin >> S;

    int N = S.size();
    vector<vector<mint>> dp(N+10, vector<mint>(N+10, 0));
    dp[0][0] = 1;
    rep(i, 0, N){
        rep(j, 0, N+1){
            if (dp[i][j] == 0) continue;
            if (S[i] == '?'){
                if (j-1>=0) dp[i+1][j-1] += dp[i][j];
                dp[i+1][j+1] += dp[i][j];
            }else if (S[i] == '('){
                dp[i+1][j+1] += dp[i][j];
            }else{
                if (j-1>=0) dp[i+1][j-1] += dp[i][j];
            }
        }
    }

    cout << dp[N][0].val() << endl;
    
    return 0;
}