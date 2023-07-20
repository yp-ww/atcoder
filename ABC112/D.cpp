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

vector<long long> divisor(long long n){
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++){
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll N, M;
    cin >> N >> M;

    vector<ll> d = divisor(M);
    ll ans = 1;
    rep(i, 0, d.size()){
        ll x = d[i];
        if (N * x > M) break;
        ans = x;
    }
    cout << ans << endl;
    
    return 0;
}