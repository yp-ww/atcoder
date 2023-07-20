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
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    set<ll> v;
    priority_queue<ll> hq;
    rep(i, 0, N){
        if (v.find(A[i]) != v.end()) continue;
        v.insert(A[i]);
        hq.push(-A[i]);
    }

    int cnt = 0;
    ll ans = 0;
    while (1){
        cnt++;
        ll now = -hq.top(); hq.pop();
        if (cnt == K) {ans = now; break;}
        rep(i, 0, N){
            ll nex = now + A[i];
            if (v.find(nex) != v.end()) continue;
            v.insert(nex);
            hq.push(-nex);
        }
    }

    cout << ans << endl;

    return 0;
}