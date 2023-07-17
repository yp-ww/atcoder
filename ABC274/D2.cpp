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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    bool dpx[N+1][21000], dpy[N+1][21000];

    dpx[1][A[0]+10000] = true;
    dpy[1][10000] = true;

    rep(i, 1, N){
        // y
        if (i % 2){
            rep(j, 0, 20001){
                dpx[i+1][j] = dpx[i][j];
                if (dpy[i][j]){
                    dpy[i+1][j+A[i]] = true;
                    dpy[i+1][j-A[i]] = true;
                }
            }
        }else{// x
            rep(j, 0, 20001){
                dpy[i+1][j] = dpy[i][j];
                if (dpx[i][j]){
                    dpx[i+1][j+A[i]] = true;
                    dpx[i+1][j-A[i]] = true;
                }
            }

        }
    }

    if (dpx[N][X+10000] && dpy[N][Y+10000]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}