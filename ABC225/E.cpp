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
    ll n;
    cin>>n;
    vector<ll>x(n),y(n);
    rep(i,0,n)cin>>x[i]>>y[i];

    vector<tuple<ll,ll,ll,ll>> arr;
    rep(i,0,n){
        arr.push_back({x[i],y[i]-1, x[i]-1,y[i]});
    }

    auto f = [](pair<ll,ll> a, pair<ll,ll> b){
        auto [x1,y1] = a;
        auto [x2,y2] = b;
        bool flag = (x2*y1 <= x1*y2);
        return x2*y1 <= x1*y2;
    };

    auto cmp = [&](tuple<ll,ll,ll,ll> a, tuple<ll,ll,ll,ll> b){
        auto [ax1,ay1,ax2,ay2] = a;
        auto [bx1,by1,bx2,by2] = b;
        return f({ax2,ay2},{bx2,by2});
    };

    stable_sort(all(arr), cmp);
    pair<ll,ll> last = {1,-1};
    ll ans = 0;
    for (auto [l1,r1,l2,r2] :arr){
        if (f(last, {l1,r1})){
            last = {l2,r2};
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}