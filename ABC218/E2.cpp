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
    int N, M;
    cin >> N >> M;

    vector<tuple<ll, int, int>> v;
    rep(i, 0, M){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        v.push_back(make_tuple(c, a, b));
    }

    sort(all(v));

    ll ans = 0;
    dsu d(N);
    for (auto tp: v){
        ll c = get<0>(tp);
        auto a = get<1>(tp);
        auto b = get<2>(tp);
        if (c <= 0){
            d.merge(a, b);
        }else{
            if (d.same(a, b)){
                ans += c;
            }else{
                d.merge(a, b);
            }
        }
    }

    cout << ans << endl;


    return 0;
}