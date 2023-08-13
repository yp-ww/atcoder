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
    int H, W, N;
    cin >> H >> W >> N;
    vector<string> G(H);
    rep(i, 0, H) cin >> G[i];
    
    vector<int> dh = {0, 0, 1, -1};
    vector<int> dw = {1, -1, 0, 0};
    vector<vector<vector<int>>> D(N+1, vector<vector<int>>(H, vector<int>(W, INF)));
    map<int, pair<int, int>> pos;
    int sh, sw;
    rep(i, 0, H) rep(j, 0, W){
        if (G[i][j] == 'S'){ sh = i; sw = j; }
        if (G[i][j] == '.' || G[i][j] == 'X' || G[i][j] == 'S') continue;
        int s = G[i][j] - '0';
        pos[s] = {i, j};
        D[s][i][j] = 0;
        queue<pair<int, int>> q;
        set<pair<int, int>> st; 
        q.push({i, j});
        st.insert({i, j});
        while (!q.empty()){
            auto p = q.front(); q.pop();
            int h1 = p.first;
            int w1 = p.second;
            rep(i, 0, 4){
                int h2 = h1 + dh[i];
                int w2 = w1 + dw[i];
                if (0 > h2 || H <= h2 || 0 > w2 || W <= w2) continue;
                if (G[h2][w2] == 'X') continue;
                if (D[s][h2][w2] != INF) continue;
                D[s][h2][w2] = D[s][h1][w1] + 1;
                q.push({h2, w2}); 
            }
        }
    }

    int ans = 0;
    int hp = 1;
    int h = sh;
    int w = sw;
    rep(i, 1, N+1){
        int s = i;
        hp += s;
        ans += D[s][h][w];
        auto p = pos[s];
        h = p.first;
        w = p.second;
    }

    cout << ans << endl;
    return 0;
}