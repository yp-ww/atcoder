#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int N, M;
ll A, B, C, D, E, F;
set<pair<ll, ll>> st;
using mint = modint998244353;
mint dp[310][310][310];

int main()
{
    cin >> N >> M;
    cin >> A >> B >> C >> D >> E >> F;
    for (int i=0; i<M; i++){
        ll x, y;
        cin >> x >> y;
        st.insert(make_pair(x, y));
    }
    
    dp[0][0][0] = 1;
    for (int n=0; n<N+1; n++){
        for (int i=0; i<n+1; i++){
            int tot = n - i;
            for (int j=0; j<tot+1; j++){
                int k = n - i - j;
                ll posx = A * i + C * j + E * k;
                ll posy = B * i + D * j + F * k;
                if (st.find(make_pair(posx, posy)) != st.end()) continue;
                if (st.find(make_pair(posx + A, posy + B)) == st.end()){
                    dp[n+1][i+1][j] += dp[n][i][j];
                }
                if (st.find(make_pair(posx + C, posy + D)) == st.end()){
                    dp[n+1][i][j+1] += dp[n][i][j];
                }
                if (st.find(make_pair(posx + E, posy + F)) == st.end()){
                    dp[n+1][i][j] += dp[n][i][j];
                }                    
            }
        }
    }

    mint ans = 0;
    for (int i=0; i<N+1; i++){
        int tot = N - i;
        for (int j=0; j<tot+1; j++){
            ans += dp[N][i][j];
        }
    }
    
    cout << ans.val() << endl;
    return 0;
}