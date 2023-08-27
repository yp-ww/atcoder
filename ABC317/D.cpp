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
    vector<ll> X(N), Y(N), Z(N);
    rep(i, 0, N) cin >> X[i] >> Y[i] >> Z[i];

    ll tot = 0;
    ll now = 0;
    vector<pair<ll, ll>> dif;
    rep(i, 0, N){
        tot += Z[i];
        if (X[i] > Y[i]){
            now += Z[i];
        }else{
            dif.push_back({Y[i]-X[i], Z[i]});
        }
    }
    ll half = (tot/2) + 1;
    vector<vector<ll>> dp(dif.size()+1, vector<ll>(tot+1, INF));
    dp[0][now] = 0;
    rep(i, 0, dif.size()) rep(j, 0, (int)tot+1){
        if (dp[i][j] == INF) continue;
        auto p = dif[i];
        ll d = p.first;
        ll z = p.second;
        chmin(dp[i+1][j], dp[i][j]);
        chmin(dp[i+1][j+z], dp[i][j]+(d/2)+1);
    }

    ll ans = INF;
    rep(i, 0, dif.size()+1) rep(j, (int)half, (int)tot+1){
        chmin(ans, dp[i][j]);
    }

    cout << ans << endl;

    return 0;
}