#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int N;
ll A[5050];
ll dp[5050][2550][2];

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];

    for (int i=0; i<N; i++){
        for (int j=0; j<min(i+1, N-i+1)+1; j++){
            for (int m=0; m<2; m++){
                if (m){
                    dp[i+1][j][(m+1)%2] = max(dp[i+1][j][(m+1)%2], dp[i][j][m] + A[j]);
                    if (j>=1){
                        dp[i+1][j-1][(m+1)%2] = max(dp[i+1][j-1][(m+1)%2], dp[i][j][m] + A[j-1]);
                    }
                    if (j+1 <= min(i+1, N-i-1)){
                        dp[i+1][j+1][m] = max(dp[i+1][j+1][m], dp[i][j][m] + A[j+1]);
                    }
                    
                }else{
                    if (j==0){
                        dp[i+1][j+1][(m+1)%2] = max(dp[i+1][j+1][(m+1)%2], dp[i][j][m] + A[j+1]);
                        dp[i+1][j+1][m] = max(dp[i+1][j+1][m], dp[i][j][m]);
                    }else{
                        dp[i+1][j-1][m] = max(dp[i+1][j-1][m], dp[i][j][m] + A[j-1]);
                    }
                }
            }
        }
    }
    
    ll ans = dp[N][0][0];
    cout << ans << endl;
    
    return 0;
}