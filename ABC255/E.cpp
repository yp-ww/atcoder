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
    ll n,m;
    cin>>n>>m;
    vector<ll>s(n-1);
    vector<ll>x(m);
    rep(i,0,n-1)cin>>s[i];
    rep(i,0,m)cin>>x[i];

    vector<ll> a(n);
    a[0] = 0;
    rep(i,0,n-1){
        a[i+1] = s[i] - a[i];
    }

    vector<ll> ev, od;
    rep(i,0,n){
        if (i%2){
            od.push_back(a[i]);
        }else{
            ev.push_back(a[i]);
        }
    }

    map<ll,int> evmp, odmp;
    for (auto z: ev){
        evmp[z]++;
    }
    for (auto z: od){
        odmp[z]++;
    }

    ll ans = 0;
    rep(i,0,m){
        for (auto [key, cnt]: odmp){
            ll temp = 0;
            ll dif = x[i] - key;
            for (auto z: x){
                if (odmp.find(z-dif) != odmp.end()){
                    temp += odmp[z-dif];
                }
                if (evmp.find(z+dif) != evmp.end()){
                    temp += evmp[z+dif];
                }
            }
            chmax(ans, temp);
        }
    }
    cout << ans << endl;

    return 0;
}