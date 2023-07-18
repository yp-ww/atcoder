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
    vector<int> A(M), B(M);
    rep(i, 0, M) cin >> A[i] >> B[i];
    int cnt = 0;
    rep(i, 0, M){
        dsu d(N);
        rep(j, 0, M){
            if (i == j) continue;
            int a = A[j] - 1;
            int b = B[j] - 1;
            d.merge(a, b);
        }
        vector<vector<int>> vec = d.groups();
        if (d.groups().size() == 1) continue;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}