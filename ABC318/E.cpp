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
const ll INF = (ll)3e15;

int main()
{
    ll n;
    cin >> n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];

    vector<vector<ll>> arr(n+1);
    rep(i,0,n){
        arr[a[i]].push_back(i+1);
    }
    ll ans = 0;
    rep(i,1,n+1){
        ll sz = arr[i].size();
        if (sz<=1) continue;
        vector<ll> dif;
        rep(j,1,sz){
            dif.push_back(arr[i][j] - arr[i][j-1] - 1);
        }
        rep(j,0,dif.size()){
            ll fo = j+1;
            ll ba = sz - fo;
            ans += fo*ba*dif[j];
        }  
    }
    cout << ans << endl;

    return 0;
}