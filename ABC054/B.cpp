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

    vector<string> A(N), B(M);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, M) cin >> B[i];

    bool ans = false;
    rep(i, 0, N) rep(j, 0, N){
        if (i + M > N) break;
        if (j + M > N) break;
        bool flag = true;
        rep(k, 0, M) rep(l, 0, M){
            if (A[i+k][j+l] != B[k][l]) flag = false;
        }
        if (flag) { ans = true; break; }
    }

    if (ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}