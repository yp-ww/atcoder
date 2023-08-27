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
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, 0, H) cin >> A[i];
    int sh, sw, gh, gw;
    rep(i, 0, H) rep(j, 0, W){
        if (A[i][j] == 'S'){
            sh = i;
            sw = j;
            continue;
        }
        if (A[i][j] == 'G'){
            gh = i;
            gw = j;
            continue;
        }if (A[i][j] == '#') continue;
        if (A[i][j] == '.') continue;
        if (A[i][j] == '!') continue;
        if (A[i][j] == 'v'){
            int cnt = 1;
            while (i + cnt < H){
                if (A[i + cnt][j] != '.' && A[i + cnt][j] != '!') break;
                A[i + cnt][j] = '!';
                cnt++;
            }
        }
        if (A[i][j] == '^'){
            int cnt = 1;
            while (i - cnt >= 0){
                if (A[i - cnt][j] != '.' && A[i - cnt][j] != '!') break;
                A[i - cnt][j] = '!';
                cnt++;
            }
        }
        if (A[i][j] == '>'){
            int cnt = 1;
            while (j + cnt < W){
                if (A[i][j + cnt] != '.' && A[i][j + cnt] != '!') break;
                A[i][j + cnt] = '!';
                cnt++;
            }
        }
        if (A[i][j] == '<'){
            int cnt = 1;
            while (j - cnt >= 0){
                if (A[i][j - cnt] != '.' && A[i][j - cnt] != '!') break;
                A[i][j - cnt] = '!';
                cnt++;
            }
        }
    }

    vector<vector<int>> dis(H, vector<int>(W, -1));

    vector<int> dh = {0, 0, 1, -1};
    vector<int> dw = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    q.push({sh, sw});
    dis[sh][sw] = 0;
    while (!q.empty()){
        auto p = q.front(); q.pop();
        int nh = p.first;
        int nw = p.second;
        rep(i, 0, 4){
            int mh = nh + dh[i];
            int mw = nw + dw[i];
            if (mh < 0 || mh >= H || mw < 0 || mw >= W) continue;
            if (A[mh][mw] != '.' && A[mh][mw] != 'G') continue;
            if (dis[mh][mw] != -1) continue;
            dis[mh][mw] = dis[nh][nw] + 1;
            q.push({mh, mw});
        }
    }

    cout << dis[gh][gw] << endl;

    return 0;
}