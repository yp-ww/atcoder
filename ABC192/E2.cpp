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
const ll INF = (ll)1e15;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    X--; Y--;
    vector<ll> A(M), B(M), T(M), K(M);
    rep(i, 0, M) cin >> A[i] >> B[i] >> T[i] >> K[i];

    vector<vector<tuple<ll, ll, ll>>> G(N);
    rep(i, 0, M){
        G[A[i]-1].push_back(make_tuple(B[i]-1, T[i], K[i]));
        G[B[i]-1].push_back(make_tuple(A[i]-1, T[i], K[i]));
    }

    priority_queue<pair<ll, ll>> hq;
    hq.push(make_pair(-0, X));
    vector<bool> v(N);
    while (!hq.empty()){
        auto p = hq.top(); hq.pop();
        ll time = - p.first;
        ll now = p.second;
        if (v[now]) continue;
        v[now] = true;
        if (v[Y]){
            cout << time << endl;
            return 0;
        }
        for (auto r: G[now]){
            ll nex = get<0>(r);
            ll cost = get<1>(r);
            ll k = get<2>(r);
            if (v[nex]) continue;
            ll t = time + (k - (time%k))%k + cost;
            hq.push(make_pair(-t, nex));
        }
    }

    cout << -1 << endl;

    return 0;
}