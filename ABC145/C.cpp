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
    int N;
    cin >> N;
    vector<double> X(N), Y(N);
    rep(i, 0, N) cin >> X[i] >> Y[i];

    vector<int> arr;
    rep(i, 0, N) arr.push_back(i);

    double tot = 0.0;
    int cnt = 0;
    do {
        double d = 0.0;
        rep(i, 1, N){
            int pre = arr[i-1];
            int now = arr[i];
            d += sqrt((X[pre]-X[now])*(X[pre]-X[now]) + (Y[pre]-Y[now])*(Y[pre]-Y[now]));
        }
        tot += d;
        cnt++;
    }while (next_permutation(all(arr)));

    double ans = tot / (double)cnt;
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}