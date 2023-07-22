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
    string S, T;
    cin >> S >> T;

    int N = S.size();
    int M = T.size();

    int pos = -1;
    rrep(i, N-M, 0){
        bool flag = true;
        rep(j, i, i+M){
            if (S[j] != T[j-i] && S[j] != '?') flag = false;
        }
        if (flag){ pos = i; break; }
    }

    if (pos == -1){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    string ans = "";
    rep(i, 0, N){
        if (pos <= i && i < pos+M){
            ans += T[i-pos];
            continue;
        }
        if (S[i] == '?'){
            ans += 'a';
        }else{
            ans += S[i];
        }
    }

    cout << ans << endl;

    return 0;
}