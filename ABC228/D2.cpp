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


int dfs(int x, vector<int> &par){
    if (x == par[x]) return x;
    int y = dfs(par[x], par);
    par[x] = y;
    return y;
}

int main()
{
    int Q;
    cin >> Q;

    vector<ll> v(1<<20, -1);
    vector<int> par(1<<20);
    rep(i, 0, 1<<20) par[i] = i;

    rep(i, 0, Q){
        int t;
        ll x;
        cin >> t >> x;
        if (t==1){
            ll h = x;
            int pos = h % (1<<20);
            pos = dfs(pos, par);
            v[pos] = x;
            par[pos] = par[(pos+1)%(1<<20)];
        }else{
            cout << v[x%(1<<20)] << endl;
        }
    }
    return 0;
}