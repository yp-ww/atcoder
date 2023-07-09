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
    ll R, X, Y;
    cin >> R >> X >> Y;
    ll r = R;
    ll x2 = X * X;
    ll y2 = Y * Y;

    int cnt = 1;
    while (1){
        if (r * r != x2 + y2 && cnt==1){
            r += R;
            cnt++;
            continue;
        }
        if (r * r >= x2 + y2){
            cout << cnt << endl;
            return 0;
        }else{
            r += R;
            cnt++;
        }
    }

    return 0;
}