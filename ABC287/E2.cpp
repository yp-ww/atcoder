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
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, 0, N) cin >> S[i];
    vector<string> T = S;
    map<string, int> mp;
    rep(i, 0, N){
        mp[S[i]] = i;
    }

    sort(all(S));
    vector<int> ans(N);
    rep(i, 1, N){
        string pre = S[i-1];
        string now = S[i];
        int cnt = 0;
        rep(j, 0, min(pre.size(), now.size())){
            if (pre[j] == now[j]){
                cnt++;
            }else{
                break;
            }
        }
        chmax(ans[mp[now]], cnt);
        chmax(ans[mp[pre]], cnt);
    }

    rep(i, 0, N) cout << ans[mp[T[i]]] << endl;

    return 0;
}