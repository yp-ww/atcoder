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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    vector<int> cnt(N+1, 0);
    rep(i, 0, N) cnt[A[i]] += 1;
    vector<int> vc;
    rep(i, 1, N+1){
        if(cnt[i]) vc.push_back(cnt[i]);
    }
    sort(vc.begin(), vc.end());
    int ans = 0;
    int l = vc.size();
    rep(i, 0, l-K) ans += vc[i];
    cout << ans << endl;
    return 0;
}