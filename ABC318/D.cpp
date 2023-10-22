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

ll flag[1LL<<16] = {false};
ll memo[1LL<<16] = {0};

int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>> g(n, vector<ll>(n));
    rep(i,0,n)rep(j,i+1,n){
        cin>>g[i][j];
    }
    function<ll(ll)> dfs = [&](ll s){
        if (flag[s]) return memo[s];
        ll now = 0;
        rep(i,0,n){
            if ((s&(1LL<<i))==0){
                now = i;
                break;
            }
        }
        ll temp = 0;
        rep(nex,now+1,n){
            if (s&(1LL<<nex)) continue;
            ll s2 = s;
            s2 += (1LL<<now)+(1LL<<nex);
            chmax(temp, dfs(s2) + g[now][nex]);
        }
        flag[s] = true;
        memo[s] = temp;
        return temp;
    };
    ll ans = 0;
    if (n%2){
        rep(i,0,n){
            chmax(ans, dfs(1LL<<i));
        }
        cout << ans << endl;
    }else{
        cout << dfs(0) << endl;
    }
    
    return 0;
}