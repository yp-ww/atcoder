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
    int n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i,0,n)rep(j,0,n)cin>>a[i][j];

    vector<vector<vector<ll>>> v1(n, vector<vector<ll>>(n)), v2(n, vector<vector<ll>>(n));

    v1[0][0].push_back(a[0][0]);
    rep(i,0,n)rep(j,0,n){
        if (i+j>=n-1) continue;
        for (auto x: v1[i][j]){
            v1[i][j+1].push_back(x^a[i][j+1]);
            v1[i+1][j].push_back(x^a[i+1][j]);
        }
    }

    v2[n-1][n-1].push_back(a[n-1][n-1]);
    rrep(i,n-1,0) rrep(j,n-1,0){
        if (i+j<n) continue;
        for (auto x: v2[i][j]){
            v2[i][j-1].push_back(x^a[i][j-1]);
            v2[i-1][j].push_back(x^a[i-1][j]);
        }
    }

    ll ans = 0;
    vector<vector<map<ll,ll>>> mp1(n, vector<map<ll,ll>>(n));
    rep(i,0,n)rep(j,0,n){
        if (i+j!=n-1) continue;
        for (auto x: v1[i][j]){
            x ^= a[i][j];
            mp1[i][j][x]++;
        }
        for (auto x: v2[i][j]){
            ans += mp1[i][j][x];
        }
    }

    cout << ans << endl;

    return 0;
}