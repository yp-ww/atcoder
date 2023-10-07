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
    ll w,h;
    cin>>w>>h;
    ll n;
    cin>>n;
    vector<ll>p(n),q(n);
    rep(i,0,n) cin>>p[i]>>q[i];
    ll A,B;
    cin>>A;
    vector<ll>a(A);
    rep(i,0,A)cin>>a[i];
    cin>>B;
    vector<ll>b(B);
    rep(i,0,B)cin>>b[i];
    vector<map<ll,ll>> g(A+2);
    rep(i,0,n){
        ll x = p[i];
        ll y = q[i];
        int xi = lower_bound(all(a), x) - a.begin();
        int yi = lower_bound(all(b), y) - b.begin();
        g[xi][yi]++;
    }
    ll _min = INF;
    ll _max = 0;
    int tot = 0;
    rep(i,0,A+1){
        for (auto [key, cnt]: g[i]){
            tot++;
            chmin(_min, cnt);
            chmax(_max, cnt);
        }
    }
    if (tot == (A+1)*(B+1)){
        cout << _min << endl;
    }else{
        cout << 0 << endl;
    }
    cout << _max << endl;

    return 0;
}