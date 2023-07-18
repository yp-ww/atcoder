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
    int N, S;
    cin >> N >> S;
    vector<vector<bool>> dp(N+1, vector<bool>(S+1, 0));
    vector<int> A(N), B(N);

    dp[0][0] = true;
    rep(i, 0, N){
        int a, b;
        cin >> a >> b;
        A[i] = a; B[i] = b;
        rep(j, 0, S){
            if (!dp[i][j]) continue;
            if (j+a <= S) dp[i+1][j+a] = true;
            if (j+b <= S) dp[i+1][j+b] = true;
        }
    }

    if (!dp[N][S]){cout << "No" << endl; return 0;}
    cout << "Yes" << endl;
    vector<char> ans;
    int pos = S;
    rrep(i, N-1, 0){
        int a = A[i];
        int b = B[i];
        if (pos-a >= 0 && dp[i][pos-a]){
            pos -= a;
            ans.push_back('H');
        }else{
            pos -= b;
            ans.push_back('T');
        }
    }
    reverse(all(ans));
    rep(i, 0, N){
        cout << ans[i];
    }
    
    return 0;
}