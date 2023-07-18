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

int N, K;
bool flag = false;
int T[10][10];

int dfs(int n, int pos, int x){
    if (n == N){
        int tot = x ^ T[n-1][pos];
        if (tot == 0) flag = true;
        return 0;
    }
    rep(nex, 0, K){
        int y = 0;
        y ^= x;
        if (n != 0) y ^= T[n-1][pos];
        dfs(n+1, nex, y);
    }
    
    return 0;
}

int main()
{
    cin >> N >> K;
    rep(i, 0, N) rep(j, 0, K) cin >> T[i][j];

    dfs(0, 0, 0);

    if (flag){
        cout << "Found" << endl;
    }else{
        cout << "Nothing" << endl;
    }

    return 0;
}