#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e15;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> X(N), Y(N), R(N);
    rep(i, 0, N) cin >> X[i] >> Y[i] >> R[i];

    vector<int> A(M), B(M);
    rep(i, 0, M) cin >> A[i] >> B[i];
    
    auto f = [](int ax, int ay, int bx, int by){
        double res = (double)(ax-bx)*(ax-bx) + (double)(ay-by)*(ay-by);
        res = sqrt(res);
        res = res / 2.0;
        return res;
    };

    vector<double> arr(M, 100000.0);
    rep(i, 0, M) rep(j, 0, M){
        if (i == j) continue;
        double r = f(A[i], B[i],A[j], B[j]);
        chmin(arr[i], r);
    }

    auto g = [](int ax, int ay, int bx, int by, int br){
        double res = (double)(ax-bx)*(ax-bx) + (double)(ay-by)*(ay-by);
        res = sqrt(res);
        res -= br;
        return res;
    };
    rep(i, 0, M) rep(j, 0, N){
        double r = g(A[i], B[i], X[j], Y[j], R[j]);
        chmin(arr[i], r);
    }

    double ans = 100000.0;
    rep(i, 0, N) chmin(ans, (double)R[i]);
    rep(i, 0, M) chmin(ans, arr[i]);

    cout << fixed << setprecision(15) << ans << endl;
    
    return 0;
}