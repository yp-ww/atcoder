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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>p(n);
    vector<vector<ll>> f(n);
    rep(i,0,n){
        ll pp,c;
        cin>>pp>>c;
        p[i]=pp;
        rep(j,0,c){
            ll ff;
            cin>>ff;
            f[i].push_back(ff);
        }
    }
    rep(i,0,n)rep(j,0,n){
        if (i==j)continue;
        if (p[i]<p[j])continue;
        bool flag = true;
        for (auto x: f[i]){
            if (find(all(f[j]),x)==f[j].end()) flag=false;
        }
        if (!flag) continue;
        if (f[j].size()>f[i].size() || p[i]>p[j]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}