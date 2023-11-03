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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n,t,m;
    cin>>n>>t>>m;
    set<pair<ll,ll>> st;
    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        st.insert({a,b});
        st.insert({b,a});
    }
    ll ans = 0;
    function<void(ll,vector<vector<ll>>)> dfs = [&](ll now, vector<vector<ll>> v){
        if (now==n+1){
            if (v.size()==t) ans++; 
            return ; 
        }
        rep(i,0,v.size()){
            bool flag = true;
            for (auto x: v[i]){
                if (st.find({x,now})!=st.end()) flag = false;
            }
            if (!flag)continue;
            auto v2 = v;
            v2[i].push_back(now);
            dfs(now+1, v2);
        }
        if (v.size() < t){
            auto v2 = v;
            v2.push_back({now});
            dfs(now+1, v2);
        }
        return ;
    };

    dfs(2, {{1}});   

    cout << ans << endl;
    return 0;
}