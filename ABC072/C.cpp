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

    vector<int> cnt(1e5+10, 0);
    rep(i, 0, N) cnt[A[i]]++;
    int ans = 0;
    rep(i, 1, 1e5+1){
        chmax(ans, cnt[i-1] + cnt[i] + cnt[i+1]);
    }
    cout << ans << endl;

    return 0;
}
