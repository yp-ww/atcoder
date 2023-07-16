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
    double x0, y0, xn, yn;
    cin >> x0 >> y0 >> xn >> yn;

    double xh = (x0 + xn) / 2.0;
    double yh = (y0 + yn) / 2.0;

    double xp = x0 - xh;
    double yp = y0 - yh;

    double z = 2.0 * pi / (double)N; 

    double x1 = xp * cos(z) - yp * sin(z) + xh;
    double y1 = xp * sin(z) + yp * cos(z) + yh;

    cout << fixed << setprecision(16);
    cout << x1 << " " << y1 << endl;

    return 0;
}