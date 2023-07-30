#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
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
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (A + B <= 2*C){
        cout << A*X + B*Y << endl;
        return 0;
    }

    if (X > Y){
        swap(A, B);
        swap(X, Y);
    }

    int ans = 0;
    ans += X * C * 2;
    
    if (B < 2*C){
        ans += (Y-X) * B;
    }else{
        ans += (Y-X) * C * 2;
    }
    cout << ans << endl;  

    return 0;
}