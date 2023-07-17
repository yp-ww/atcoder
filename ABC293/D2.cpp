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
    int N, M;
    cin >> N >> M;

    dsu uf(N*2);
    // R: i
    // B: N + i
    rep(i, 0, N){
        uf.merge(i, N+i);
    }

    int x = 0;
    rep(i, 0, M){
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a--; c--;
        if (b == 'B') a += N;
        if (d == 'B') c += N;
        if (uf.same(a, c)) x++;
        uf.merge(a, c);
    }

    int y = uf.groups().size() - x;
    
    cout << x << " " << y << endl;

    return 0;
}
