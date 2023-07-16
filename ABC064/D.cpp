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
    int N;
    cin >> N;
    string S;
    cin >> S;

    int cnt = 0;
    rrep(i, N-1, 0){
        if (S[i] == ')'){
            cnt++;
        }else{
            cnt--;
            chmax(cnt, 0);
        }
    }
    int a = cnt;

    cnt = 0;
    rep(i, 0, N){
        if (S[i] == '('){
            cnt++;
        }else{
            cnt--;
            chmax(cnt, 0);
        }
    }
    int b = cnt;

    string ans = "";
    rep(i, 0, a){
        ans += '(';
    }

    rep(i, 0, N){
        ans += S[i];
    }

    rep(i, 0, b){
        ans += ')';
    }

    cout << ans << endl;

    return 0;
}