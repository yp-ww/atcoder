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
    string S;
    cin >> S;

    if (count(S.begin(), S.end(), 'o') > 4){
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 0;
    rep(x, 0, 10000){
        vector<bool> vc(10);

        rep(i, 0, 4){
            int y = x / pow(10, i);
            y %= 10;
            vc[y] = true;
        }
        
        bool flag = true;
        rep(i, 0, 10){
            if (S[i] == 'o'){
                if (!vc[i]) flag = false; 
            }
            if (S[i] == 'x'){
                if (vc[i]) flag = false;
            }
        }
        if (flag) ans++;
    }

    cout << ans << endl;

    return 0;
}