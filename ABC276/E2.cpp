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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, 0, H) cin >> S[i];
    int sh, sw;
    rep(i, 0, H) rep(j, 0, W){
        if (S[i][j] == 'S'){
            sh = i; sw = j;
        }
    }

    vector<int> dh = {0, 0, 1, -1};
    vector<int> dw = {1, -1, 0, 0};

    bool flag = false;

    rep(i, 0, 4){
        if (0 <= sh + dh[i] && sh + dh[i] < H && 0 <= sw + dw[i] && sw + dw[i] < W){
            if (S[sh + dh[i]][sw + dw[i]] == '#') continue;
                queue<pair<int, int>> q;
                q.push(make_pair(sh + dh[i], sw + dw[i]));
                vector<vector<bool>> v(H, vector<bool>(W, false));
                v[sh + dh[i]][sw + dw[i]] = true;
                while (!q.empty()){
                    int now_h = q.front().first;
                    int now_w = q.front().second;
                    q.pop();
                    rep(j, 0, 4){
                        if (0 <= now_h + dh[j] && now_h + dh[j] < H && 0 <= now_w + dw[j] && now_w + dw[j] < W){
                            if (v[now_h + dh[j]][now_w + dw[j]]) continue;
                            if (S[now_h + dh[j]][now_w + dw[j]] == '.'){
                                q.push(make_pair(now_h + dh[j], now_w + dw[j]));
                                v[now_h + dh[j]][now_w + dw[j]] = true;
                            }
                        }
                    }
                }
                int cnt = 0;
                rep(j, 0, 4){
                    if (0 <= sh + dh[j] && sh + dh[j] < H && 0 <= sw + dw[j] && sw + dw[j] < W){
                        if (v[sh + dh[j]][sw + dw[j]]) cnt++;
                    }
                }
                if (cnt >= 2) flag = true;
        }
    }

    if (flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}