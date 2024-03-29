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
    int n;
    cin>>n;

    
    vector<string> a(n);
    rep(i,0,n)cin>>a[i];

    vector<bitset<3010>> b(n);

    rep(i,0,n)rep(j,0,n){
        b[i][j] = a[i][j]-'0';
    }

    ll ans = 0;
    rep(i,0,n){
        rep(j,i+1,n){
            if (a[i][j]=='0')continue;
            ans += (b[i]&b[j]).count();
        }
    }
    cout << ans/3 << endl;

    return 0;
}