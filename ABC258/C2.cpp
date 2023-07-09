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
    int N, Q;
    string S;
    cin >> N >> Q;
    cin >> S;

    int pos = 0;
    rep(i, 0, Q){
        int t, x;
        cin >> t >> x;
        if (t == 1){
            pos += x;
            pos %= N;
        }else{
            x--;
            cout << S[(N-pos+x)%N] << endl;
        }
    }
    return 0;
}