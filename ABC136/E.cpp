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

vector<long long> divisor(long long n){
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++){
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];

    ll tot = accumulate(all(a), 0LL);
    vector<ll> arr = divisor(tot);
    sort(all(arr));
    ll ans = 0;
    for (auto x: arr){
        vector<ll> b(n);
        rep(i,0,n) b[i] = a[i]%x;
        sort(all(b));
        vector<ll>cum(n+1);
        rep(i,0,n)cum[i+1] = cum[i]+b[i];
        vector<ll> c(n);
        rep(i,0,n) c[i] = x - b[i];
        vector<ll> cum2(n+1);
        rep(i,0,n)cum2[i+1] = cum2[i]+c[i];
        ll pos = -1;
        rep(i,0,n){
            if (cum[i+1] == cum2[n] - cum2[i+1]){
                pos = i;
                break;
            }
        }
        if (pos == -1) continue;
        if (cum[pos+1] > k) continue;
        ans = x;
    }
    cout << ans << endl;

    return 0;
}