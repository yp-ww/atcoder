#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e15;

using mint = modint998244353;
int main()
{
    int n,p;
    cin>>n>>p;
    vector<mint> dp(n+1);
    mint pp = p;
    pp /= 100;
    mint qq = 1-pp;
    dp[0] = 0;
    dp[1] = 1;
    rep(i,2,n+1){
        dp[i] = dp[i-2]*pp + dp[i-1]*qq + 1;
    }
    cout << dp[n].val() << endl;

    return 0;
}