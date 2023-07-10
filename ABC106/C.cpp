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
    ull K;
    cin >> K;

    int num = 1;
    int idx = 100;
    rep(i, 0, S.size()){
        if (S[i] != '1'){
            num = S[i] - '0';
            idx = i+1;
            break;
        }
    }
    
    if (idx <= K){
        cout << num << endl;
    }else{
        cout << 1 << endl;
    }

    return 0;
}