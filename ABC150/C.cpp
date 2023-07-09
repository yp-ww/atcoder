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
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    rep(i, 0, N) cin >> P[i];
    rep(i, 0, N) cin >> Q[i];

    vector<int> vc(N);
    rep(i, 1, N+1) vc[i-1] = i;
    ll p, q;
    ll cnt = 0;
    do{
        cnt++;
        bool pf = true;
        bool qf = true;
        rep(i, 0, N) if(vc[i] != P[i]) pf = false;
        rep(i, 0, N) if(vc[i] != Q[i]) qf = false;
        if(pf) p = cnt;
        if(qf) q = cnt;        
    }while(next_permutation(vc.begin(), vc.end()));

    cout << abs(p-q) << endl;

    return 0;
}
