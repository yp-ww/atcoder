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
const ll INF = (ll)1e15;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N+1), B(N+1);
    rep(i, 1, N+1) cin >> A[i];
    rep(i, 1, N+1) B[i] = B[i-1] + A[(i+1)/2];
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, -INF));

    dp[0][0] = 0;
    rep(i, 0, N) rep(j, 0, N){
        if (dp[i][j] < 0) continue;
        chmax(dp[i+1][j+1], dp[i][j]);
        chmax(dp[i+1][0], dp[i][j] + B[j]);
    }

    cout << dp[N][0] << endl;    

    return 0;
}