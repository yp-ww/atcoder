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
    int R, C;
    cin >> R >> C;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    vector<string> S(R);
    rep(i, 0, R) cin >> S[i];
    queue<pair<int, int>> q;
    vector<vector<int>> v(R, vector<int>(C, -1));

    vector<int> dh = {-1, 1, 0, 0}, dw = {0, 0, -1, 1};

    q.push({sy, sx});
    v[sy][sx] = 0;
    while (!q.empty()){
        auto p = q.front(); q.pop();
        rep(i, 0, 4){
            int nh = p.first + dh[i];
            int nw = p.second + dw[i];
            if (S[nh][nw] == '#') continue;
            if (v[nh][nw] != -1) continue;
            v[nh][nw] = v[p.first][p.second] + 1;
            q.push({nh, nw});
        }
    }

    cout << v[gy][gx] << endl;

    return 0;
}