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


int T = 0;
void solve(ll a, ll s){
    ll temp = a & (s-a);
    if (s >= 2*a && temp == a){
        cout << "Yes" << endl;
        return ;
    }else{
        cout << "No" << endl;
        return ;
    }

}


int main()
{
    cin >> T;
    rep(i, 0, T){
        ll a, s;
        cin >> a >> s;
        solve(a, s);
    }

    return 0;
}