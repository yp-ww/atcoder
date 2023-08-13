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
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<vector<ll>> dp(N+1, vector<ll>(21, 0LL));
    dp[0][0] = 1LL;
    rep(i, 0, N-1) rep(j, 0, 21){
        if (dp[i][j] == 0) continue;
        if (j + A[i] < 21) dp[i+1][j+A[i]] += dp[i][j];
        if (i != 0 && j - A[i] >= 0) dp[i+1][j-A[i]] += dp[i][j];
    }  

    cout << dp[N-1][A[N-1]] << endl;
    
    return 0;
}