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
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<int>> cum(10, vector<int>(N+1, 0));
    
    rep(i, 0, N){
        char s = S[i];
        int num = s - '0';
        cum[num][i+1] = 1;
    }

    rep(i, 0, 10){
        rep(j, 0, N){
            cum[i][j+1] += cum[i][j];
            cum[i][j+1] %= 2;
        }
    }
    
    vector<int> cnt(1<<10, 0);
    cnt[0] += 1;
    rep(j, 1, N+1){
        int k = 0;
        rep(i, 0, 10){
            if (cum[i][j] == 1){
                k += (1 << i);
            }
        }
        cnt[k] += 1;
    }

    ll ans = 0;
    rep(k, 0, 1<<10){
        ll c = cnt[k];
        if (c <= 1) continue;
        ans += c * (c-1) / 2;
    }

    cout << ans << endl;

    return 0;
}