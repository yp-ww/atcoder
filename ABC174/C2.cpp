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
    int K;
    cin >> K;

    if (K%2==0){
        cout << -1 << endl;
        return 0;
    }

    ll cnt = 0;
    ll now = 0;
    ll b = 7;
    vector<bool> v(K);
    while (cnt < (ll)1e7+1){
        now += b;
        now %= K;
        v[now] = true;
        cnt++;
        b *= 10;
        b %= K;
        if (v[0]) break;
    }

    if (!v[0]){
        cout << -1 << endl;
    }else{
        cout << cnt << endl;
    }
   

    return 0;
}