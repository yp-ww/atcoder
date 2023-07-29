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
const ll INF = (ll)1e15;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N;
    cin >> N;
    vector<ll> X(N), Y(N), H(N);
    rep(i, 0, N) cin >> X[i] >> Y[i] >> H[i];

    int pos = 0;
    rep(i, 0, N){
        if (H[i] > 0){ pos = i; break; }
    }

    rep(x, 0, 101){
        rep(y, 0, 101){
            ll h = abs((ll)x-X[pos]) + abs((ll)y-Y[pos]) + H[pos];
            bool flag = true;
            rep(i, 0, N){
                if (H[i] != max(h - abs((ll)x-X[i]) - abs((ll)y-Y[i]), 0LL)){
                    flag = false;
                    break;
                }
            }
            if (flag){
                cout << x << " " << y << " " << h << endl;
            }
    
        }
    }
    return 0;
}