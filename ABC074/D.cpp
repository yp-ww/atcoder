#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e15;

int main()
{
    int N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    rep(i, 0, N) rep(j, 0, N) cin >> A[i][j];
    bool flag = true;
    rep(k, 0, N) rep(i, 0, N) rep(j, 0, N){
        if (i == j || i == k || j == k) continue;
        if (A[i][j] > A[i][k] + A[k][j]) flag = false;
    }
    if (!flag) { cout << -1 << endl; return 0; }

    rep(k, 0, N) rep(i, 0, N) rep(j, 0, N){
        if (i == j || i == k || j == k) continue;
        if (A[i][j] == (A[i][k] + A[k][j])) A[i][j] = INF;
    }

    ll ans = 0LL;
    rep(i, 0, N) rep(j, i, N){
        if (A[i][j] == INF) continue;
        ans += A[i][j];
    }
    cout << ans << endl;

    return 0;
}