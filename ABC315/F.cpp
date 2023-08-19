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
const double INF = 1e15;

int main()
{
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, 0, N) cin >> X[i] >> Y[i];

    auto f = [&](int a, int b){
        return sqrt((X[a]-X[b])*(X[a]-X[b]) + (Y[a]-Y[b])*(Y[a]-Y[b]));
    };

    vector<vector<double>> dp(N+1, vector<double>(50, INF));
    dp[0][0] = 0;
    rep(i, 0, N-1) rep(j, 0, 50){
        if (dp[i][j] == INF) continue;
        rep(k, 0, 50){
            if (i+k+1 < N && j+k < 50) chmin(dp[i+k+1][j+k], dp[i][j] + f(i, i+k+1));
        }
    }

    double ans = dp[N-1][0];
    rep(j, 1, 50){
        chmin(ans, dp[N-1][j] + (double)pow(2, j-1));
    }
    cout << std::fixed << std::setprecision(15) << ans << endl;

    return 0;
}