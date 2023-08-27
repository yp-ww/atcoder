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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> C(10, vector<int>(10));
    rep(i, 0, 10) rep(j, 0, 10) cin >> C[i][j];
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, 0, H) rep(j, 0, W) cin >> A[i][j];

    vector<vector<int>> d(10, vector<int>(10, 1000000000));
    rep(i, 0, 10) rep(j, 0, 10){
        d[i][j] = C[i][j];
    }
    rep(k, 0, 10) rep(i, 0, 10) rep(j, 0, 10){
        chmin(d[i][j], d[i][k] + d[k][j]);
    }
    
    int ans = 0;
    rep(i, 0, H) rep(j, 0, W){
        if (A[i][j] == -1) continue;
        ans += d[A[i][j]][1];
    }
    cout << ans << endl;

    return 0;
}