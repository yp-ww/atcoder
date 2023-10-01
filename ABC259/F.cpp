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

bool flag[305000][2] = {false};
ll memo[305000][2];

int main()
{
    ll n;
    cin>>n;
    vector<ll>d(n);
    rep(i,0,n)cin>>d[i];

    vector<vector<pair<ll,ll>>> g(n);
    rep(i,0,n-1){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    function<ll(ll,ll,ll)> dfs = [&](ll now, ll pre, ll cnt){
        // cout << now << " " << pre << " " << cnt << endl;
        if (flag[now][cnt]) return memo[now][cnt];
        ll cnt2 = cnt;
        vector<tuple<ll,ll,ll>> tp;
        for (auto [nex, score]: g[now]){
            if (nex == pre) continue;
            ll temp1 = -INF;
            ll temp0 = 0;
            if (d[nex]>0 && d[now]-cnt>0 && score>0){
                chmax(temp1, dfs(nex, now, 1) + score);
                chmax(temp0, dfs(nex, now, 0));
            }else{
                chmax(temp0, dfs(nex, now, 0));
            }
            tp.push_back({temp1-temp0, temp1, temp0});
        }

        sort(all(tp));
        reverse(all(tp));
        ll res = 0;
        for (auto [dif,t1,t0]: tp){
            if (d[now]-cnt>0 && dif > 0){
                res += t1; 
                cnt++;
            }else{
                res += t0;
            }
        }
        flag[now][cnt2] = true;
        memo[now][cnt2] = res;
        return res;
    };

    ll ans = dfs(0, -1, 0);
    cout << ans << endl;
    
    return 0;
}