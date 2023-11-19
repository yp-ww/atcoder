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
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    sort(all(a));

    ll ans = 0;
    ll cnt = 0;
    rep(i,0,16){
        vector<ll>arr;
        ll mod = 1LL;
        rep(j,0,i+1) mod *= 10LL;
        rep(j,0,n){
            arr.push_back(a[j]%mod);
        }
        sort(all(arr));
        rep(j,0,n){
            ll rem = mod - arr[j];
            ll temp = lower_bound(all(arr), rem) - arr.begin();
            cnt += n-temp;
        }
    }

    rep(i,0,n){
        ll d = a[i];
        while(d){
            ans += d%10;
            d/=10;
        }
    }
    ans *= 2;
    ans *= n;
    ans -= 9*cnt;
    cout << ans << endl;
    
    return 0;
}