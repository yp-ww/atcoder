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
    ll n,L;
    cin>>n>>L;
    ll k;
    cin>>k;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    ll l = 0;
    ll r = INF;
    a.push_back(L);
    n++;
    while(r-l>1){
        ll mid = (l+r)/2;
        ll now = 0;
        ll pre = 0;
        ll cnt = 0;
        rep(i,0,n){
            now += a[i] - pre;
            pre = a[i];
            if (now>=mid){
                now = 0;
                cnt++;
            }
        }
        if (cnt<k+1) r = mid;
        else l = mid;
    }
    cout << l << endl;
    return 0;
}