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
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];

    vector<vector<ll>> s(n,vector<ll>(n));
    vector<tuple<ll,int,int>> arr;
    rep(i,0,n)rep(j,i+1,n){
        s[i][j] = pow_mod(a[i], a[j], m);
        s[i][j] += pow_mod(a[j],a[i], m);
        s[i][j] %= m;
        arr.push_back({s[i][j],i,j});
    }
    
    auto cmp = [](tuple<ll,int,int> tpa, tuple<ll,int,int> tpb){
        return get<0>(tpa) > get<0>(tpb);
    };
    sort(all(arr), cmp);
    ll ans = 0;
    dsu d(n);
    for (auto [c,i,j]: arr){
        if (d.same(i,j)) continue;
        d.merge(i,j);
        ans += s[i][j];
    }

    cout << ans << endl;

    return 0;
}