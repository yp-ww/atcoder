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
    vector<int> arr;
    rep(i, 1, 15){
        ll a = pow(6, i);
        if (a <= N){arr.push_back(a);}else{break;}
    }
    rep(i, 1, 15){
        ll a = pow(9, i);
        if (a <= N){arr.push_back(a);}else{break;}
    }
    
    int INF = (int)1e6;
    vector<vector<int>> dp(arr.size()+1, vector<int>(N+1, INF));
    dp[0][0] = 0;
    rep(i, 0, arr.size()){
        rep(j, 0, N+1){
            if (dp[i][j] == INF) continue;
            int cnt = 0;
            int a = arr[i];
            while (j + a * cnt <= N){
                chmin(dp[i+1][j+a*cnt], dp[i][j] + cnt);
                cnt++;
            }
        }
    }
    
    int ans = INF;
    rep(j, 0, N+1){
        chmin(ans, N - j + dp[arr.size()][j]);
    }
    cout << ans << endl;
    return 0;
}