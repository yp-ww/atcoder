#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<vector<int>>> A(H, vector<vector<int>>(W, vector<int>(N+1)));
    set<int> st;
    rep(i, 0, H) rep(j, 0, W){
        int a;
        cin >> a;
        A[i][j][a] = 1;
        st.insert(a);
    }

    vector<vector<vector<int>>> cum(H+1, vector<vector<int>>(W+1, vector<int>(N+1)));
    rep(i, 1, H+1) rep(j, 1, W+1) rep(k, 1, N+1){
        cum[i][j][k] = cum[i-1][j][k] + cum[i][j-1][k] - cum[i-1][j-1][k] + A[i-1][j-1][k];
    }

    rep(a, 0, H-h+1){
        rep(b, 0, W-w+1){
            int ans = st.size();
            rep(k, 1, N+1){
                if (st.find(k) == st.end()) continue;
                int cnt = cum[a+h][b+w][k] - cum[a+h][b][k] - cum[a][b+w][k] + cum[a][b][k];
                if (cum[H][W][k] - cnt == 0) ans -= 1;
            }
            cout << ans << " ";
        }
        cout << endl;        
    }

    return 0;
}