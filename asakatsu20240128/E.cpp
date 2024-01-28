#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define smod(n, m) ((((n) % (m)) + (m)) % (m)) // 非負mod
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

inline int popcount(int n) { return __builtin_popcount(n); } // 2進数で表した場合に立ってるビット数がいくつか
inline int popcount(ll n) { return __builtin_popcountll(n); }
inline int ctz(int n) { return n != 0 ? __builtin_ctz(n) : -1; } // 2進数で表した場合に 1 の位からいくつ 0 が連なっているか
inline int ctz(ll n) { return n != 0 ? __builtin_ctzll(n) : -1; }
inline int clz(int n) { return n != 0 ? (31 - __builtin_clz(n)) : -1; } // 2進数で表した場合に左側にいくつ 0 を埋める必要があるか
inline int clz(ll n) { return n != 0 ? (63 - __builtin_clzll(n)) : -1; }

const double PI = 3.141592653589793;
const vector<int> DX = { 1, 0, -1, 0 };
const vector<int> DY = { 0, 1, 0, -1 };
const long long INF = (ll)1e18+10;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

int main()
{
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll>p(n-1),t(n-1);
    rep(i,0,n-1)cin>>p[i]>>t[i];
    vector<vector<ll>> dp(840,vector<ll>(n+1));
    rep(i,0,840)dp[i][0] = i;
    rep(i,0,840)rep(j,0,n-1){
        ll now = dp[i][j];
        ll rem = now%p[j];
        ll cost = 0;
        if (rem) cost += p[j] - rem;
        dp[i][j+1] = dp[i][j] + t[j] + cost;
    }

    rep(i,0,840)dp[i][n] = dp[i][n-1] + y - dp[i][0];
    ll q;
    cin>>q;
    while(q--){
        ll c;
        cin>>c;
        ll mode = (c+x)%840;
        cout << dp[mode][n] + c + x << endl;
    }
    
    // cout << fixed << setprecision(18);
    return 0;
}