#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)3e15;

ll g[110][110] = {0};

int main()
{
    ll n;
    cin>>n;
    rep(i,0,n){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        rep(x,a,b)rep(y,c,d){
            g[x][y]++;
        }
    }
    ll cnt=0;
    rep(i,0,101)rep(j,0,101){
        if (g[i][j]) cnt++;
    }
    cout << cnt << endl;

    return 0;
}