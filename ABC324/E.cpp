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
    cin>>n;
    string t;
    cin>>t;
    vector<string>s(n), rs(n);
    rep(i,0,n) cin>>s[i];
    vector<ll> fo(n), ba(n);
    rep(i,0,n){
        ll pos = 0;
        rep(j,0,s[i].size()){
            if (s[i][j]==t[pos]){
                pos++;
            }
        }
        fo[i] = pos;
    }
    rep(i,0,n) reverse(all(s[i]));
    reverse(all(t));

    rep(i,0,n){
        ll pos = 0;
        rep(j,0,s[i].size()){
            if (s[i][j]==t[pos]){
                pos++;
            }
        }
        ba[i] = pos;
    }
    vector<ll>fcnt(t.size()+10), bcnt(t.size()+10);
    vector<ll>fcum(t.size()+20), bcum(t.size()+10);
    rep(i,0,n){
        fcnt[fo[i]]++;
        bcnt[ba[i]]++;
    }
    rep(i,0,t.size()+5){
        fcum[i+1] = fcum[i] + fcnt[i];
        bcum[i+1] = bcum[i] + bcnt[i];
    }
    ll ans = 0;
    rep(i,0,n){
        ll res = t.size()-fo[i];
        ll tot = bcum[t.size()+1] - bcum[res];
        ans += tot;
    }
    cout << ans << endl;

    
    return 0;
}