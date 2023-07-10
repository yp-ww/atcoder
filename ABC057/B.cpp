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
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N), C(M), D(M);
    rep(i, 0, N) cin >> A[i] >> B[i];
    rep(i, 0, M) cin >> C[i] >> D[i];

    rep(i, 0, N) {
        ll temp = 1e10;
        int idx = M;
        rrep(j, M-1, 0){
            ll d = abs(A[i]-C[j])+abs(B[i]-D[j]);
            if(temp >= d){
                temp = d;
                idx = j;
            }
        }
        cout << idx+1 << endl;
    }


    return 0;
}