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
    int n;
    cin>>n;
    vector<ll>x(n),c(n);
    rep(i,0,n)cin>>x[i];
    rep(i,0,n)cin>>c[i];

    vector<ll> out(n);

    rep(i,0,n){
        out[x[i]-1]+=c[i];
    }
    priority_queue<pair<ll,int>> hp;
    rep(i,0,n){
        hp.push({-out[i],i});
    }
    ll ans = 0;
    vector<bool> v(n);
    while(!hp.empty()){
        auto [cost,idx] = hp.top(); hp.pop();
        if (v[idx]) continue;
        v[idx] = true;
        ans += -1*cost;
        out[x[idx]-1] -= c[idx];
        hp.push({-out[x[idx]-1], x[idx]-1});
    }
    cout << ans << endl;

    return 0;
}