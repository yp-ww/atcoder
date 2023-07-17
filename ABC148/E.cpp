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
    ull N;
    cin >> N;

    if (N % 2){cout << 0 << endl; return 0;}
    
    ull ans = 0;
    rep(i, 1, 26){
        ull a = pow(5, i);
        ull b = (N / a) / 2;
        ans += b;
    }

    cout << ans << endl;

    return 0;
}