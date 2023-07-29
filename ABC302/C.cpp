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
const ll INF = (ll)1e15;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, 0, N) cin >> S[i];

    sort(all(S));
    bool flag = false;
    do{
        bool flag2 = true;
        rep(i, 0, N-1){
            int cnt = 0;
            rep(j, 0, M){
                if (S[i][j] != S[i+1][j]) cnt++;
            }
            if (cnt > 1) { flag2 = false; break; }
        }
        if (flag2) { flag = true; break; }
    }while (next_permutation(all(S)));

    if (flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}