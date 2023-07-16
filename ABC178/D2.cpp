#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

using mint = modint1000000007;
vector<bool> flag(2100, false);
vector<mint> memo(2100);

// mint f(int x){
//     if (x < 3) return 0;
//     if (flag[x]) return memo[x];

//     mint res = 1;
//     rep(i, 3, x){
//         if (x-i < i) break;
//         if (x-i < 3) break;
//         if (x-i == i) {res += f(i); break;}
//         res += f(x-i) + f(i);
//     }

//     memo[x] = res;
//     flag[x] = true;
//     return res;
// }

mint f2(int x){
    if (x == 0) return 1;
    if (x < 3) return 0;
    if (flag[x]) return memo[x];

    mint res = f2(x-1) + f2(x-3);
    memo[x] = res;
    flag[x] = true;
    return res;

}

int main()
{
    int S;
    cin >> S;

    cout << f2(S).val() << endl;

    return 0;
}