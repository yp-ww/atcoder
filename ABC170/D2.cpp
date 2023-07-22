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
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(all(A));

    vector<int> cnt(1000100);
    rep(i, 0, N) cnt[A[i]]++;

    vector<bool> v(1000100);
    int ans = 0;
    rep(i, 0, N){
        int p = A[i];
        if (v[p]) continue;
        if (cnt[p] == 1) ans++;
        int q = p;
        while (q < 1000100){
            v[q] = true;
            q += p;
        }
    }

    cout << ans << endl;

    return 0;
}