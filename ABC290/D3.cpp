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
    int t;
    cin>>t;
    rep(_,0,t){
        ll n,d,k;
        cin>>n>>d>>k;
        // 一周に何回か
        ll cir = lcm(d,n)/d;
        // 何周分か
        ll cnt = (k-1)/cir;
        // 残り何回か
        ll rem = (k-1)%cir;
        // 今どこか
        ll now = cnt + rem*d;
        ll ans = now%n;
        cout << ans << endl;
    }
    return 0;
}