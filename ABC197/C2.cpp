#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    ll ans = (ll)1e15;

    rep(k, 0, 1<<(N-1)){
        vector<ll> arr;
        int pos = 0;
        ll x = A[pos];
        while (pos < N){
            if (pos == N-1) {arr.push_back(x); break;}
            if (k>>pos & 1){
                arr.push_back(x);
                x = A[pos+1];
                pos++;
            }else{
                x |= A[pos+1];
                pos++;
            }
        }
        ll y = 0;
        for (auto temp: arr){
            y ^= temp;
        }
        chmin(ans, y);
    }
    cout << ans << endl;

    return 0;
}