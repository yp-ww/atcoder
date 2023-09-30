#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e15;

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>a(n),b(n),c(m),d(m);
    rep(i,0,n)cin>>a[i]>>b[i];
    rep(i,0,m)cin>>c[i]>>d[i];

    long double l = 0.0, r = 1.0;
    while (r-l > 0.0000000000001){
        long double mid = (l+r)/2.0;
        vector<double> ab(n),cd(m);
        rep(i,0,n) ab[i] = a[i]-(a[i]+b[i])*mid;
        rep(i,0,m) cd[i] = (c[i]+d[i])*mid-c[i];
        sort(all(ab));
        sort(all(cd));
        ll cnt = 0;
        rep(i,0,n){
            ll idx = upper_bound(all(cd), ab[i]) - cd.begin();
            cnt += idx;
        }
        if (cnt>=k){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << fixed << setprecision(15) << l*100.0 << endl;

    return 0;
}