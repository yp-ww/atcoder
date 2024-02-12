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

#define endl "\n" // インタラクティブの時はコメントアウトする

vector<ll> f(vector<vector<ll>> &graph, ll st = 0){
    ll sz = graph.size();
    vector<ll> v(sz, INF);
    queue<ll> q;
    q.push(st);
    v[st] = 0;
    while(!q.empty()){
        auto now = q.front(); q.pop();
        for (auto nex: graph[now]){
            if (v[nex]!=INF) continue;
            q.push(nex);
            v[nex] = v[now] + 1;
            if (nex==sz-1) return v;
        }
    }
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);
    
    ll n,m;
    cin>>n>>m;
    vector<ll>s(m),t(m);
    rep(i,0,m)cin>>s[i]>>t[i];
    rep(i,0,m) s[i]--;
    rep(i,0,m) t[i]--;

    vector<vector<ll>> to(n);
    vector<vector<pair<ll,ll>>> ba(n);
    rep(i,0,m){
        to[s[i]].push_back(t[i]);
        ba[t[i]].push_back({s[i],i});
    }
    auto v = f(to);
    if (v[n-1]==INF){
        rep(i,0,m) cout << -1 << endl;
        return 0;
    }

    set<ll> st;
    ll now = n-1;
    ll d = v[n-1];
    while(d){
        for (auto [nex,idx]: ba[now]){
            if (v[nex]==d-1){
                now = nex;
                d--;
                st.insert(idx);
                break;
            }
        }
    }

    rep(i,0,m){
        if (st.find(i)==st.end()){
            cout << v[n-1] << endl;
            continue;
        }
        vector<vector<ll>> g(n);
        rep(j,0,m){
            if (i==j) continue;
            g[s[j]].push_back(t[j]);
        }
        auto v2 = f(g);
        if (v2[n-1]==INF) cout << -1 << endl;
        else cout << v2[n-1] << endl;
    }

    return 0;
}