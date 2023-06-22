#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int N, M;
long double X[20], Y[20];
long double dp[1<<20][20];
long double INF;

long double cost(long double x1, long double y1, long double x2, long double y2, ll v){
    long double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return d / (long double)v;
}


int main()
{
    cin >> N >> M;
    for (int i=M+1; i<=N+M; i++) cin >> X[i] >> Y[i];
    for (int i=1; i<=M; i++) cin >> X[i] >> Y[i];

    INF = 1e15 + 7;
    for (int k=0; k<(1<<(N+M+1)); k++){
        for (int i=0; i<(N+M+1); i++){
            dp[k][i] = INF;
        }
    }

    dp[0][0] = 0;
    for (int k=0; k<(1<<(N+M+1)); k++){
        for (int i=0; i<(N+M+1); i++){
            if (dp[k][i] == INF) continue;

            ll v = 1;
            for (int j=1; j<M+1; j++){
                if ((k >> j) & 1) v *= 2;
            }
            for (int j=0; j<(N+M+1); j++){
                if ((k >> j) & 1) continue;
                dp[k+(1<<j)][j] = min(dp[k+(1<<j)][j], dp[k][i] + cost(X[i], Y[i], X[j], Y[j], v));
            }
        }
    }

    long double ans = INF;
    for (int k=0; k<(1<<(N+M+1)); k++){
        bool flag = true;
        for (int j=M+1; j<N+M+1; j++){
            if (!((k >> j) & 1)) flag = false;
        }
        if (!(k & 1)) flag = false;
        if (!flag) continue;
        // cout << dp[k][0] << endl;
        ans = min(ans, dp[k][0]);
    }

    cout << fixed << setprecision(10);
    cout << ans << endl;
    // cout << INF << endl;
    return 0;
}