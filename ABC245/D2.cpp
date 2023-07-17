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
    vector<ll> A(N+1, 0);
    rep(i, 0, N+1) cin >> A[i];
    vector<ll> C(N+M+1, 0);
    rep(i, 0, N+M+1) cin >> C[i];

    vector<ll> B(M+1, 0);
    B[M] = C[N+M] / A[N];
    rrep(i, M-1, 0){
        B[i] = C[N+i];
        int pos = i;
        pos++;
        while (pos <= M){
            if (N+i-pos < 0) break;
            B[i] -= A[N+i-pos] * B[pos];
            pos++;
        }
        B[i] /= A[N];
    }
    
    rep(i, 0, M+1){
        cout << B[i] << " ";
    }

    return 0;
}