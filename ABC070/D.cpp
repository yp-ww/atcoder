#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()

const double pi = 3.141592653589793;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    ll N;
    cin >> N;
    vector<vector<pair<ll, ll>>> G(N);
    rep(i, 0, N-1){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    ll Q, K;
    cin >> Q >> K;
    K--;

    vector<ll> dis(N);
    vector<bool> v(N);

    function<void(ll, ll)> dfs = [&](ll now, ll d){
        v[now] = true;
        dis[now] = d;
        for (auto p: G[now]){
            auto nex = p.first;
            if (v[nex]) continue;
            auto c = p.second;
            dfs(nex, d + c);
        }
    };

    dfs(K, 0);

    rep(i, 0, Q){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << dis[x] + dis[y] << endl;
    }

    return 0;
}