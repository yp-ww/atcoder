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
    ll n;
    cin>>n;
    vector<vector<ll>> g(n);
    rep(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    queue<ll>q;
    q.push(0);
    vector<ll>v(n,-1);
    v[0] = 0;
    while(!q.empty()){
        ll now = q.front(); q.pop();
        for (auto nex: g[now]){
            if (v[nex]!=-1) continue;
            v[nex] = v[now] + 1;
            q.push(nex);
        }
    }

    ll idx = max_element(all(v)) - v.begin();
    q.push(idx);
    vector<ll>v2(n,-1);
    v2[idx] = 0;
    while(!q.empty()){
        ll now = q.front(); q.pop();
        for(auto nex: g[now]){
            if (v2[nex]!=-1)continue;
            v2[nex] = v2[now] + 1;
            q.push(nex);
        }
    }

    ll ans = *max_element(all(v2)) + 1;
    cout << ans << endl;
    return 0;
}