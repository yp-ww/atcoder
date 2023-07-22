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
    vector<vector<int>> F(N, vector<int>(10, 0));
    rep(i, 0, N) rep(j, 0, 10) cin >> F[i][j];

    vector<vector<int>> P(N, vector<int>(11, 0));
    rep(i, 0, N) rep(j, 0, 11) cin >> P[i][j];

    ll INF = (ll)1e15;
    ll ans = -INF;
    rep(k, 1, 1<<10){
        ll temp = 0;
        rep(i, 0, N){
            int cnt = 0;
            rep(j, 0, 10){
                if ((k>>j)&1 && F[i][j]) cnt++;
            }
            temp += P[i][cnt];
        }
        chmax(ans, temp);
    }

    cout << ans << endl;

    return 0;
}