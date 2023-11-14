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
    ll n,m;
    cin>>n>>m;
    vector<ll>p(n),c(n);
    vector<vector<ll>>f(n);
    rep(i,0,n){
        cin>>p[i]>>c[i];
        rep(j,0,c[i]){
            ll ff;
            cin>>ff;
            ff--;
            f[i].push_back(ff);
        }
    }
    bool flag = false;
    rep(i,0,n){
        vector<bool>f1(m);
        for (auto x: f[i]){
            f1[x] = true;
        }
        rep(j,0,n){
            if (i==j)continue;
            if (p[i]<p[j])continue;
            auto f2 = f1;
            for (auto x: f[j]){
                f2[x] = false;
            }
            bool flag2 = false;
            rep(k,0,m) flag2 |= f2[k];
            if (flag2)continue;
            if (p[i]>p[j]) flag = true;
            if (f[i].size()<f[j].size()) flag =true;
        }
    }
    YesNo(flag);
    return 0;
}