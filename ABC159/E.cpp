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
    ll h,w,k;
    cin>>h>>w>>k;
    vector<string>s(h);
    rep(i,0,h)cin>>s[i];

    vector<vector<ll>> cum(h+1, vector<ll>(w+1,0));
    rep(i,1,h+1)rep(j,1,w+1){
        ll c = 0;
        if (s[i-1][j-1] == '1') c = 1;
        cum[i][j] = cum[i-1][j] + cum[i][j-1] - cum[i-1][j-1] + c;
    }

    ll ans = INF;
    rep(bit, 0, 1<<(h-1)){
        vector<pair<ll,ll>> arr;
        ll now = 0;
        ll cnt = 0;
        rep(i,0,h-1){
            if (bit&(1<<i)){
                arr.push_back({now, i+1});
                now = i+1;
                cnt++;
            }
        }
        arr.push_back({now, h});

        ll l = 0;
        bool ng = false;
        rep(r,1,w+1){
            bool flag = true;
            for (auto [h0,h1]: arr){
                ll temp = cum[h1][r] - cum[h1][l] - cum[h0][r] + cum[h0][l];
                if (temp > k){ flag = false; break; } 
            }
            if (!flag){
                if (r-1==l) { ng = true; break; }
                else { cnt++; l=r-1; }
            }
        }
        if (ng) continue;
        chmin(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}