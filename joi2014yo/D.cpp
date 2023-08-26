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
    string S;
    cin >> S;
    ll MOD = 10007;
    vector<vector<ll>> dp(1<<3, vector<ll>(N+1, 0));
    dp[1][0] = 1LL;

    rep(j, 0, N) rep(i, 0, 8){
        if (dp[i][j] == 0) continue;
        int nex = 0;
        if (S[j] == 'J'){
            nex = 1;
        }else if (S[j] == 'O'){
            nex = 2;
        }else{
            nex = 4;
        }
        rep(k, 0, 8){
            if ((i & k) == 0) continue;
            if ((nex & k) == 0) continue;
            dp[k][j+1] += dp[i][j];
            dp[k][j+1] %= MOD; 
        }
    } 

    ll ans = 0;
    rep(i, 0, 8){
        ans += dp[i][N];
    }

    ans %= MOD;
    cout << ans << endl;


    return 0;
}