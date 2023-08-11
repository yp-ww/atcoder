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
    double a, b, x;
    cin >> a >> b >> x;
    
    double V = a*a*b/2.0;
    double ans = 0.0;

    if (x <= V){
        ans = atan(2.0*x/(a*b*b));
    }else{
        ans = atan(a*a*a/(2.0*a*a*b-2.0*x));
    }

    ans = ans / pi * 180.0;
    cout << fixed << setprecision(10) << 90.0 - ans << endl;

    return 0;
}