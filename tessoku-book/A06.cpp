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
    ll n,q;
    cin>>n>>q;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<ll>cum(n+1);
    rep(i,0,n){
        cum[i+1] = cum[i]+a[i];
    }
    while (q){
        q--;
        ll l,r;
        cin>>l>>r;
        l--;r--;
        cout << cum[r+1] - cum[l] << endl;
    }
    return 0;
}