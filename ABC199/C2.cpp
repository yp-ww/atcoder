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
    int Q;
    cin >> Q;

    vector<char> s(N*2);
    rep(i, 0, N*2) s[i] = S[i];
    
    int mode = 0;
    rep(i, 0, Q){
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if(t == 1){
            if(mode){
                swap(s[(a+N)%(N*2)], s[(b+N)%(N*2)]);
            }else{
                swap(s[a], s[b]);
            }
        }else{
            mode++;
            mode %= 2;
        }
    }

    if(mode){
        rep(i, 0, N*2) cout << s[(N+i)%(N*2)];

    }else{
        rep(i, 0, N*2) cout << s[i];
    }

    return 0;
}