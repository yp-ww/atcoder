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

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<tuple<ll,ll,ll>>> g(n);
    rep(i,0,m){
        ll u,v,b,c;
        cin>>u>>v>>b>>c;
        u--;v--;
        g[u].push_back({v,b,c});
    }
    

    double l = 0.0;
    double r = 10e9;
    while(r-l>0.0000000001){
        double mid = (l+r)/2.0;
        vector<double> dp(n, -INF);
        dp[0] = 0;
        rep(i,0,n){
            for (auto [nex,p,c]: g[i]){
                chmax(dp[nex], dp[i]+p-mid*c);           
            }
        }
        if (dp[n-1]>=0){
            l = mid;
        }else{
            r = mid;
        }
    }
    
    cout << fixed << setprecision(15) << l << endl;

    return 0;
}