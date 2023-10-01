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

using mint = modint998244353;

mint dp[2020][2] = {0};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    rep(i,0,n) cin>>s[i];

	vector<int> top(m, n);
	rep(i,0,n)rep(j,0,m){
        if (s[i][j]=='#') chmin(top[j], i);
    }

    vector<vector<mint> > dp(m+1, vector<mint>(n+1));
	rep(i,0,top[0]+1) dp[0][i] = 1;
    vector<mint> cum(n+2, 0);
    rep(i,0,n+1) cum[i+1] = cum[i] + dp[0][i];

	rep(j,1,m){
        rrep(i,top[j],0){
		    dp[j][i] = cum[n+1] - cum[max(i-1,0)];
        }
        rep(i,0,n+1) cum[i+1] = 0;
        rep(i,0,n+1) cum[i+1] = cum[i] + dp[j][i];
	}

    cout << cum[n+1].val() << endl;

    return 0;
}