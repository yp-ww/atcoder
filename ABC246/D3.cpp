#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e30;

int main()
{
    ll n;
    cin>>n;
    ll ma = 1000100;
    ll ans = INF;
    rep(a,0,ma+1){
        ll l = a-1;
        ll r = ma;
        while (r-l>1){
            ll mid = (l+r)/2;
            bool flag = false;
            ll temp = a*a*a + a*a*mid + a*mid*mid + mid*mid*mid;
            if (temp>=n) flag = true;
            if (flag){
                r = mid;
            }else{
                l = mid;
            }
        }
        chmin(ans, a*a*a + a*a*r + a*r*r + r*r*r);
    }
    cout << ans << endl;
    return 0;
}