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
const ll INF = (ll)1e15;

ll x[1510][1510] = {0};
ll cum[1510][1510] = {0};
int main()
{
    ll h,w;
    cin>>h>>w;
    rep(i,0,h)rep(j,0,w)cin>>x[i][j];

    rep(i,0,h)rep(j,0,w){
        cum[i+1][j+1] = cum[i][j+1] + cum[i+1][j] - cum[i][j] + x[i][j];
    }

    ll q;
    cin>>q;
    while (q){
        q--;
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;
        cout << cum[c][d] - cum[c][b] - cum[a][d] + cum[a][b] << endl;
    }
    return 0;
}