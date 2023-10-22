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
const ll INF = (ll)3e15;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>t(m),w(m),s(m);
    rep(i,0,m)cin>>t[i]>>w[i]>>s[i];
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> hq1;
    priority_queue<ll, vector<ll>, greater<ll>> hq0;
    rep(i,0,n){
        hq0.push(i);
    }
    vector<ll>ans(n);
    rep(i,0,m){
        ll now = t[i];
        while (!hq1.empty()){
            auto [time, who] = hq1.top();
            if (time <= now){
                hq1.pop();
                hq0.push(who);
            }else{
                break;
            }
        }
        if (hq0.empty()) continue;
        ll pos = hq0.top();
        ans[pos] += w[i];
        hq0.pop();
        hq1.push({now+s[i], pos});
    }
    rep(i,0,n){
        cout << ans[i] << endl;
    }
    
    return 0;
}