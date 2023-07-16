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
    int K;
    cin >> K;
    
    queue<ll> q;
    vector<ll> ans{0};

    rep(i, 1, 10) q.push(i);
    while (ans.size() < 101000){
        ll now = q.front(); q.pop();
        ans.push_back(now);
        ll x = now % 10;
        if (x-1>=0) q.push(now*10+x-1);
        q.push(now*10+x);
        if (x+1<10) q.push(now*10+x+1);
    }

    cout << ans[K] << endl;

    return 0;
}