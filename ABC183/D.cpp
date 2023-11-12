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
    ll n,w;
    cin>>n>>w;
    map<ll,ll> mp;
    rep(i,0,n){
        ll s,t,p;
        cin>>s>>t>>p;
        mp[s] += p;
        mp[t] -= p;
    }
    bool flag = true;
    ll now = 0;
    for (auto [t,c]: mp){
        now += c;
        if (now>w) flag = false;
    }
    YesNo(flag);

    return 0;
}