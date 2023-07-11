#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }


int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    ll ans = 0;
    rep(i, 0, N) ans += A[i]-1;    
    
    cout << ans << endl;

    return 0;
}