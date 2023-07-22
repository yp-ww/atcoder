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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N*2, 0);
    rep(i, 0, N) cin >> A[i];
    ll tot = accumulate(A.begin(), A.end(), 0LL);
    sort(all(A));

    rep(i, 0, N) A[i] = A[i+N];

    int pos = 0;
    rep(i, 0, N-1){
        if (A[i+1] - A[i] > 1){
            pos = i+1;
            break;
        }
    }
    
    ll INF = (ll)1e20;
    ll ans = INF;
    ll temp = 0;
    rep(i, pos, pos+N){
        temp += A[i];
        if (A[i+1]%M != A[i]%M && (A[i]+1)%M != A[i+1]%M){ 
            chmin(ans, tot - temp);
            temp = 0;
        }
    }

    if (ans == INF){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}