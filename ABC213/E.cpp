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
    ll h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,0,h)cin>>s[i];
    
    deque<tuple<ll,ll,ll>> q;
    q.push_back({0,0,0});
    vector<vector<ll>> v(h,vector<ll>(w, -1));
    vector<ll> dh = {0,0,1,-1};
    vector<ll> dw = {1,-1,0,0};
    while (!q.empty()){
        auto [c,hh,ww] = q.front(); q.pop_front();
        if (v[hh][ww]!=-1)continue;
        v[hh][ww] = c;
        if (hh==h-1 && ww==w-1) break;
        rep(i,0,4){
            if (0<=hh+dh[i] && hh+dh[i]<h && 0<=ww+dw[i] && ww+dw[i]<w){
                if (s[hh+dh[i]][ww+dw[i]] == '.'){
                    q.push_front({c,hh+dh[i],ww+dw[i]});
                }
            }
        }
        rep(i,-2,3)rep(j,-2,3){
            if (abs(i)+abs(j)>3)continue;
            if (0<=hh+i && hh+i<h && 0<=ww+j && ww+j<w){
                q.push_back({c+1,hh+i,ww+j});
            }
        }
    }
    cout << v[h-1][w-1] << endl;

    return 0;
}