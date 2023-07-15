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
    sort(A.begin(), A.end());
    
    ll ans = 0;
    rep(j, 1, N-1){
        auto it = lower_bound(A.begin(), A.end(), A[j]);
        int l = it - A.begin();
        if (l == 0) continue;
        auto it2 = upper_bound(A.begin(), A.end(), A[j]);
        int r = it2 - A.begin();
        if (r == N) continue;
        ans += (ll)l * (ll)(N-r);
    }

    cout << ans << endl;

    return 0;
}