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
    ll h,w;
    cin>>h>>w;
    ll sh,sw,gh,gw;
    cin>>sh>>sw>>gh>>gw;
    sh--;sw--;gh--;gw--;
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];
    using P = pair<ll,ll>;
    deque<pair<P,ll>> q;
    vector<vector<ll>> d(h,vector<ll>(w,INF));
    q.push_front({{sh,sw},0});
    while(!q.empty()){
        auto [p,now] = q.front(); q.pop_front();
        auto [nh,nw] = p;
        if (d[nh][nw] != INF) continue;
        d[nh][nw] = now;
        rep(dh,-1,2)rep(dw,-1,2){
            if (abs(dh)+abs(dw)>1) continue;
            ll nxh = nh + dh;
            ll nxw = nw + dw;
            if (nxh<0 || nxw<0 || nxh>=h || nxw>=w) continue;
            if (d[nxh][nxw] != INF) continue;
            if (s[nxh][nxw]=='.'){
                q.push_front({{nxh,nxw},now});
            }
        }
        rep(dh,-2,3)rep(dw,-2,3){
            ll nxh = nh + dh;
            ll nxw = nw + dw;
            if (nxh<0 || nxw<0 || nxh>=h || nxw>=w) continue;
            if (d[nxh][nxw] != INF) continue;
            if (s[nxh][nxw]=='.'){
                q.push_back({{nxh,nxw},now+1});
            }
        }
    }
    if (d[gh][gw]==INF) cout << -1 << endl;
    else cout << d[gh][gw] << endl;
    return 0;
}