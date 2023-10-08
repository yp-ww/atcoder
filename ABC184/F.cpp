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

int main()
{
    ll n,t;
    cin>>n>>t;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    vector<ll> fir(n/2), sec(n-n/2);
    rep(s,0,1<<n/2){
        ll temp = 0;
        rep(i,0,n/2){
            if (s&(1LL<<i)){
                temp += a[i];
            }
        }
        fir.push_back(temp);
    }
    rep(s,0,1<<(n-n/2)){
        ll temp = 0;
        rep(i,0,(n-n/2)){
            if (s&(1LL<<i)){
                temp += a[n/2+i];
            }
        }
        sec.push_back(temp);
    }

    ll ans = 0;
    sort(all(sec));
    for (auto x: fir){
        ll dif = t-x+1;
        ll idx = lower_bound(all(sec), dif) - sec.begin();
        if (idx == 0) continue;
        chmax(ans, sec[idx-1]+x);
    }
    cout << ans << endl;
    
    return 0;
}