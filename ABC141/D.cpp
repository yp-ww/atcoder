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

    priority_queue<ll> hq;
    rep(i, 0, N) hq.push(A[i]);

    rep(i, 0, M){
        ll x = hq.top(); hq.pop();
        hq.push(x/2); 
    }

    ll ans = 0;
    while (!hq.empty()){
        ans += hq.top(); hq.pop();
    }

    cout << ans << endl;

    return 0;
}