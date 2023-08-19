#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const int INF = (int)1e9+10;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> D(N), C(M);
    rep(i, 0, N) cin >> D[i];
    rep(i, 0, M) cin >> C[i];
    
    vector<vector<int>> dp(M+1, vector<int>(N+1, INF));
    dp[0][0] = 0;
    rep(i, 0, M) rep(j, 0, N+1){
        if (dp[i][j] == INF) continue;
        chmin(dp[i+1][j], dp[i][j]);
        if (j+1 <= N) chmin(dp[i+1][j+1], dp[i][j] + D[j]*C[i]);
    }

    cout << dp[M][N] << endl;

    return 0;
}