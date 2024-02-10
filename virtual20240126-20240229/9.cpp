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

using mint = modint998244353;
bool flag[202000][2][2];
mint memo[202000][2][2];

int main()
{
    ll n;
    cin>>n;
    vector<ll> p(n),q(n);
    rep(i,0,n)cin>>p[i];
    rep(i,0,n)cin>>q[i];
    rep(i,0,n)p[i]--;
    rep(i,0,n)q[i]--;

    dsu uf(n);
    rep(i,0,n){
        uf.merge(p[i],q[i]);
    }

    function<mint(ll,ll,ll)> f = [&](ll now, ll mode, ll init){
        if (flag[now][mode][init]) return memo[now][mode][init];
        if (init){
            if (now==1) return (mint)1;
        }
        if (!init){
            if (now==1 && mode==1) return (mint)1;
            if (now==1 && mode==0) return (mint)0;
        }

        mint res = 0;
        if (mode){
            res += f(now-1,mode,init);
            res += f(now-1,mode^1,init);
        }else{
            res += f(now-1,mode^1,init);
        }
        flag[now][mode][init] = true;
        return memo[now][mode][init] = res;
    };

    f(n,1,1);
    f(n,0,0);
    mint ans = 1;
    for(auto arr: uf.groups()){
        ll sz = arr.size();
        ans *= f(sz,1,1) + f(sz,0,0);
    }
    cout << ans.val() << endl;


    // cout << fixed << setprecision(18);
    return 0;
}