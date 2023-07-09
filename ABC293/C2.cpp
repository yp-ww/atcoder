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

ll G[15][15];

int f(int h, int w, vector<int> v){
    v.push_back(G[h][w]);
    if(h==0 && w==0){
        if(set(v.begin(), v.end()).size() == v.size()){
            return 1;
        }else{
            return 0;
        }
    }
    int res = 0;
    if(0<=h-1) res += f(h-1, w, v);
    if(0<=w-1) res += f(h, w-1, v);
    return res;
}

int main()
{
    int H, W;
    cin >> H >> W;
    rep(i, 0, H) rep(j, 0, W) cin >> G[i][j];
    vector<int> v;
    int ans = f(H-1, W-1, v);
    cout << ans << endl;
    return 0;
}