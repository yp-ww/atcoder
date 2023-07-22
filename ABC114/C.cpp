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
    ll N;
    cin >> N;

    vector<vector<ll>> v(10);
    v[1] = {3, 5, 7};
    rep(i, 2, 10){
        for (ll p: {3, 5, 7}){
            for (ll q: v[i-1]){
                v[i].push_back(p*pow(10, i-1) + q);
            }
        }
    }

    int ans = 0;
    rep(i, 3, 10){
        for (ll p: v[i]){
            if (p <= N){
                string s = to_string(p);
                if (s.find("3") == string::npos) continue;
                if (s.find("5") == string::npos) continue;
                if (s.find("7") == string::npos) continue;
                ans++;
            }else{
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}