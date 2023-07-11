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
    ll N, H;
    cin >> N >> H;
    vector<ll> A(N), B(N);
    rep(i, 0, N) cin >> A[i] >> B[i];
    
    ll a = *max_element(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    ll cnt = 0;
    int pos = 0;
    while (H > 0){
        if (pos < N && B[pos] > a){
            H -= B[pos];
            cnt += 1;
            pos += 1;
        }else{
            cnt += H / a;
            if (H % a) cnt += 1;
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}