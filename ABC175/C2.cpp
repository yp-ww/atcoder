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
    ll X;
    ull K, D;
    cin >> X >> K >> D;
    chmax(X, -1 * X);
    X = (ull)X;

    if (X >= K * D){
        cout << X - K * D << endl;
    }else{
        ull cnt = K - X / D;
        ull d = X - (X/D) * D;
        if (cnt%2){
            cout << D - d << endl;
        }else{
            cout << d << endl;
        }
    }

    return 0;
}