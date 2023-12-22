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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>g(n);

    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll>vis(n);
    function<ll(ll,vector<ll>)> dfs = [&](ll now, vector<ll> v){
        vis[now] = true;

        set<ll> st;
        for (auto nex: g[now]){
            if (!vis[nex]) continue;
            st.insert(v[nex]);
        }
        ll res = 3 - st.size();
        
        ll c = 0;
        rep(i,0,3){
            if (st.find(i)!=st.end())continue;
            c = i;
            break;
        }
        v[now] = c;
        for (auto nex: g[now]){
            if (vis[nex]) continue;
            res *= dfs(nex, v);
        }
        return res;
    };

    vector<ll> init(n, -1);
    ll ans = 1;
    rep(i,0,n){
        if (vis[i])continue;
        ll temp = dfs(i, init);
        cout << temp << endl;
        ans *= temp;
    }

    cout << ans << endl;

    return 0;
}