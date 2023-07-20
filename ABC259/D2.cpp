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
    int N;
    cin >> N;

    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    auto f = [](ll x1, ll y1, ll x2, ll y2){
        ll dis2 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        return dis2;
    };

    vector<ll> X(N), Y(N), R(N);
    rep(i, 0, N){
        ll x, y, r;
        cin >> x >> y >> r;
        X[i] = x; Y[i] = y; R[i] = r;
    }

    dsu d(N+2);
    rep(i, 0, N) rep(j, i+1, N){
        ll dis2 = f(X[i], Y[i], X[j], Y[j]);
        ll r1 = R[i];
        ll r2 = R[j];
        if (r1 > r2) swap(r1, r2);
        if ((r1+r2)*(r1+r2) < dis2) continue;
        if (r2 > r1 + sqrt(dis2)) continue;
        d.merge(i, j);
    }

    rep(i, 0, N){
        if ((X[i]-sx)*(X[i]-sx) + (Y[i]-sy)*(Y[i]-sy) == R[i]*R[i]) d.merge(i, N);
        if ((X[i]-tx)*(X[i]-tx) + (Y[i]-ty)*(Y[i]-ty) == R[i]*R[i]) d.merge(i, N+1);
    }

    if (d.same(N, N+1)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}