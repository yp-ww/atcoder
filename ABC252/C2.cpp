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
    vector<string> S(N);
    rep(i, 0, N) cin >> S[i];
    
    int ans = 100100;
    rep(x, 0, 10){
        vector<int> cnt(10, 0);
        rep(i, 0, N) rep(j, 0, 10){
            if (S[i][j] - '0' == x) cnt[j]++;
        }
        int m = *max_element(cnt.begin(), cnt.end());
        int idx = 0;
        rep(j, 0, 10){
            if (cnt[j] == m) idx = j;
        }
        chmin(ans, 10*(m-1)+idx);
    }

    cout << ans << endl;


    return 0;
}