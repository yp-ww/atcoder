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
const ll INF = (ll)1e18+10;

int main()
{
    ll h,w;
    cin>>h>>w;
    vector<vector<ll>> a(h,vector<ll>(w));
    rep(i,0,h)rep(j,0,w)cin>>a[i][j];
    
    vector<vector<ll>>ans(h,vector<ll>(w));
    vector<ll> dh(h), dw(w);
    rep(i,0,h)rep(j,0,w){
        dh[i] += a[i][j];
        dw[j] += a[i][j];
    }

    rep(i,0,h)rep(j,0,w){
        ans[i][j] += dh[i];
        ans[i][j] += dw[j];
        ans[i][j] -= a[i][j];
    }

    rep(i,0,h){
        rep(j,0,w){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}