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
    vector<ll> A(N+1);
    rep(i, 1, N+1) cin >> A[i];
    A[0] = A[N];

    vector<ll> dp(N+1, INF);
    dp[0] = 0;
    dp[1] = A[1];
    dp[2] = A[1];
    rep(i, 3, N+1){
        chmin(dp[i], dp[i-1]+A[i]);
        chmin(dp[i], dp[i-2]+A[i-1]);
    }

    ll ans = INF;
    chmin(ans, dp[N]);

    rep(i, 0, N+1) dp[i] = INF;
    dp[0] = dp[N] = A[0];
    dp[1] = A[0];
    rep(i, 2, N){
        chmin(dp[i], dp[i-1]+A[i]);
        if (i>1) chmin(dp[i], dp[i-2]+A[i-1]);
    }    
    chmin(ans, dp[N-1]);

    cout << ans << endl;       

    return 0;
}