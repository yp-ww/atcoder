#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(x) (x).begin(),(x).end()

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, 0, H) cin >> S[i];

    rep(i, 0, H) rep(j, 0, W){
        if (S[i][j] == '.') continue;
        bool flag = false;
        if (0 <= i-1){
            if (S[i-1][j] == '#') flag = true;
        }
        if (0 <= j-1){
            if (S[i][j-1] == '#') flag = true;
        }
        if (i+1 < H){
            if (S[i+1][j] == '#') flag = true;
        }
        if (j+1 < W){
            if (S[i][j+1] == '#') flag = true;
        }
        if (!flag){
            cout << "No" << endl; 
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}