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
    string s;
    cin>>s;
    ll n = s.size();
    string t;
    rep(i,0,n){
        t += '0';
        t += s[i];
    }
    t += '0';
    n = t.size();
    ll ans = 0;
    rep(i,0,n){
        ll pos = 0;
        ll cnt = 0;
        while (1){
            pos++;
            if (i-pos<0) break;
            if (i+pos>=n) break;
            if (t[i-pos] == t[i+pos]) cnt++;
            else break; 
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}