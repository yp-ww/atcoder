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
    int N;
    cin >> N;
    vector<ll> A, B;
    rep(i, 0, N){
        ll x, y;
        cin >> x >> y;
        A.push_back(x+y);
        B.push_back(x-y);
    }
    sort(all(A));
    sort(all(B));
    ll d = max(A[N-1] - A[0], B[N-1] - B[0]);
    cout << d << endl;
    return 0;
}