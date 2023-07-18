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

#define CMAX 1010
bool noinit = true;
ll memo[CMAX][CMAX];
ll nCk(int n, int k){
    if (noinit) {
        rep(i, 0, CMAX) rep(j, 0, CMAX) memo[i][j] = -1;
        noinit = false;
    }
    if (k == 0 || n == k) return 1;
    if (0 <= memo[n][k]) return memo[n][k];
    return memo[n][k] = nCk(n - 1, k - 1) + nCk(n - 1, k);
}

int main()
{
    int A, B;
    ll K;
    cin >> A >> B >> K;

    int a = A;
    int b = B;
    string ans = "";
    ll now = 0;
    rep(i, 0, A+B){
        if (a == 0){
            ans += 'b';
            continue;
        }
        if (b == 0){
            ans += 'a';
            continue;
        }
            
        ll temp = nCk(a+b-1, b);
        now += temp;
        if (now >= K){
            ans += 'a';
            now -= temp;
            a--;
        }else{
            ans += 'b';
            b--;
        }
    }   

    cout << ans << endl;
    
    return 0;
}