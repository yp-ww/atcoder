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
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];
    dsu uf(h*w+1);
    rep(i,0,h)rep(j,0,w){
        if(s[i][j]=='.'){
            uf.merge(i*w+j,h*w);
            continue;
        }
        rep(dh,-1,2)rep(dw,-1,2){
            if (dh==0 && dw==0)continue;
            if (0<=i+dh&&i+dh<h&&0<=j+dw&&j+dw<w){
                if (s[i+dh][j+dw]=='#'){
                    uf.merge(i*w+j, (i+dh)*w+j+dw);
                }
            }
        }
    }
    auto v = uf.groups();
    cout << v.size()-1 << endl;
    return 0;
}