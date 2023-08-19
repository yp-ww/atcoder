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
const int INF = (int)1e8;

int main()
{
    int D, N;
    cin >> D >> N;
    vector<int> T(D);
    rep(i, 0, D) cin >> T[i];

    vector<int> A(N), B(N), C(N);
    rep(i, 0, N) cin >> A[i] >> B[i] >> C[i];

    vector<vector<int>> dp(D, vector<int>(101, -INF));
    rep(j, 0, N){
        if (A[j] <= T[0] && T[0] <= B[j]){
            dp[0][C[j]] = 0;
        }
    }

    rep(i, 0, D-1) rep(j, 0, 101){
        if (dp[i][j] == -INF) continue;
        rep(k, 0, N){
            if (A[k] <= T[i+1] && T[i+1] <= B[k]){
                chmax(dp[i+1][C[k]], dp[i][j] + abs(j-C[k]));
            }
        }
    }

    int ans = *max_element(all(dp[D-1]));
    cout << ans << endl;


    return 0;
}