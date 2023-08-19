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
    int N, K;
    cin >> N >> K;
    int MOD = 10000;
    vector<int> A(N+1, -1);
    rep(i, 0, K){
        int a, b;
        cin >> a >> b;
        A[a] = b;
    }
    A[0] = 0;
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(4, vector<int>(3)));
    
    dp[0][0][1] = 1;
    rep(i, 0, N){
        rep(j, 0, 4){
            rep(k, 1, 3){
                if (dp[i][j][k] == 0) continue;
                if (A[i] != -1 && A[i] != j) continue;
                rep(nex, 1, 4){
                    if (A[i+1] != -1 && A[i+1] != nex) continue;
                    if (j == nex){
                        if (k+1 >= 3) continue;
                        dp[i+1][nex][k+1] += dp[i][j][k];
                        dp[i+1][nex][k+1] %= MOD;
                    }else{
                        dp[i+1][nex][1] += dp[i][j][k];
                        dp[i+1][nex][1] %= MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(j, 1, 4){
        rep(k, 1, 3){
            ans += dp[N][j][k];
            ans %= MOD;
        }
    }

    cout << ans << endl;


    return 0;
}