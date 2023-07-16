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

int main()
{
    int Q;
    cin >> Q;
    
    queue<ll> q;
    priority_queue<ll> hq;

    rep(i, 0, Q){
        int y;
        cin >> y;
        if (y == 1){
            ll x;
            cin >> x;
            q.push(x);
        }else if (y == 2){
            ll x = 0;
            if (!hq.empty()){
                x = - hq.top(); hq.pop();
            }else{
                x = q.front(); q.pop();
            }
            cout << x << endl;

        }else{
            while (!q.empty()){
                ll x = q.front(); q.pop();
                hq.push(-x);
            }
        }
    }

    return 0;
}