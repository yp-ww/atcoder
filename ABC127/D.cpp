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
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    
    vector<pair<ll, int>> v;
    
    rep(i, 0, N){
        v.push_back(make_pair(A[i], 1));
    }

    rep(i, 0, M){
        int b;
        ll c;
        cin >> b >> c;
        v.push_back(make_pair(c, b));
    }

    sort(all(v));
    reverse(all(v));
    int cnt = 0;
    ll ans = 0;
    for (auto p: v){
        ll a = p.first;
        int b = p.second;
        if (cnt + b > N){
            ans += (N - cnt) * a;
            break;
        }
        ans += b * a;
        cnt += b;
    }

    cout << ans << endl;

    return 0;
}