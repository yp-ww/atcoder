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

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<vector<int>> G(N);
    rep(i, 0, M){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<pair<ll, ll>> P;
    rep(i, 0, N){
        P.push_back({A[i], i});
    }
    
    priority_queue<pair<ll,ll>> hq;
    vector<ll> C(N);
    rep(i, 0, N){
        ll cost = 0;
        for (auto nex: G[i]){
            cost += A[nex];
        }
        hq.push({-cost, i});
        C[i] = cost;
    }

    vector<bool> v(N);
    ll ans = 0;
    while (!hq.empty()){
        auto p = hq.top(); hq.pop();
        ll cost = -1*p.first;
        ll now = p.second;
        if (v[now]) continue;
        v[now] = true;
        chmax(ans, cost);
        for (auto nex: G[now]){
            if (v[nex]) continue;
            C[nex] -= A[now];
            hq.push({-C[nex], nex});
        }
    }

    cout << ans << endl;

    return 0;
}