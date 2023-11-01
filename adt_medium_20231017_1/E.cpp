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
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n), b(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    vector<ll>c;
    rep(i,0,n)c.push_back(a[i]);
    rep(i,0,m)c.push_back(b[i]);
    sort(all(c));
    map<ll,ll>mp;
    rep(i,0,n+m){
        mp[c[i]] = i+1;
    }
    for (auto x: a){
        cout << mp[x] << endl;
    }
    for (auto y: b){
        cout << mp[y] << endl;
    }

    return 0;
}