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
    ll n;
    cin>>n;
    vector<ll> s(n),c(n);
    rep(i,0,n) cin>>s[i]>>c[i];

    map<ll,ll> mp;
    rep(i,0,n){
        mp[s[i]] = c[i];
    }
    
    ll ans = 0;
    auto itr = mp.begin();
    while(itr!=mp.end()){
        auto [now,val] = *itr;
        if (val<=1){ ans++; itr++; continue;}
        if (val%2){
            ans++;
            mp[now*2]+=(val-1)/2;
        }else{
            mp[now*2]+=(val)/2;
        }
        itr++;
    }
    cout << ans << endl;
    return 0;
}