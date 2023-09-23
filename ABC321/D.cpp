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
    ll n,m,p;
    cin>>n>>m>>p;
    vector<ll>a(n),b(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];

    sort(all(a));
    sort(all(b));

    vector<ll> cum(m+1,0);
    rep(i,1,m+1){
        cum[i] = cum[i-1]+b[i-1];
    }

    ll ans = 0;
    rep(i,0,n){
        ll now = a[i];
        int l=0;
        int r=m;
        while (r-l>1){
            int mid = (l+r)/2;
            if (now+b[mid]>p){
                r=mid;
            }else{
                l=mid;
            }
        }
        if (a[i]+b[l]>p){
            ans += p*m;
        }else{
            ans += cum[r];
            ans += a[i]*r;
            ans += p*(m-r);
        }
    }
    cout << ans << endl;


    return 0;
}