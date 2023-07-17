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

vector<bool> eratosthenes(int N) {
    vector<bool> isprime(N+1, true);
    isprime[0] = isprime[1] = false;
    rep(p, 2, N+1){
        if (!isprime[p]) continue;
        int q = p + p;
        while (q < N+1){isprime[q] = false; q += p;}
    }
    return isprime;
}

int main()
{
    int Q;
    cin >> Q;

    int MAX = (int)1e5+100;
    vector<bool> v = eratosthenes(MAX);
    vector<int> cum(MAX, 0);

    rep(i, 2, MAX-1){
        if (v[i]) if (v[(i+1)/2]){
            cum[i+1] += 1;
        }
        cum[i+1] += cum[i];
    }

    rep(i, 0, Q){
        int l, r;
        cin >> l >> r;
        int ans = cum[r+1] - cum[l];
        cout << ans << endl;
    }
    
    return 0;
}