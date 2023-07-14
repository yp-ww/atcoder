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

int main(){
    int N;
    cin >> N;

    int MAX = 1001;
    vector<int> p;
    vector<bool> v(MAX);
    rep(i, 2, MAX){
        if (v[i]) continue;
        p.push_back(i);
        int c = i;
        while (c < MAX){
            v[c] = true;
            c += i;
        }
    }

    vector<int> arr(MAX, 0);
    rep(i, 2, N+1){
        int x = i;
        for (auto q: p){
            if (x == 1) break;
            if (x % q) continue;
            int c = 0;
            while (x % q == 0){
                x /= q;
                arr[q] += 1;
            }
        }
    }

    ll MOD = (ll)1e9 + 7;
    ll ans = 1;
    rep(i, 2, N+1){
        if (arr[i] == 0) continue;
        ans *= (ll)arr[i] + 1;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}