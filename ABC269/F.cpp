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

using mint = modint998244353;

int main()
{
    ll n,m,q;
    cin>>n>>m>>q;

    rep(i,0,q){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;

        ll st = m*(a-1) + c;
        ll dh = b-a+1;
        ll dw = d-c+1;
        auto f = [&](ll h, ll w, ll s){
            mint l = s + ((h-1)/2)*(2*m) + ((w-1)/2)*2;
            mint res = ((s+l)/2) * ((h+1)/2) * ((w+1)/2);
            return res;
        };

        mint ans = 0;
        if ((a+c)%2){
            ans += f(dh, dw-1, st+1);
            ans += f(dh-1, dw, st+m);
        }else{
            ans += f(dh, dw, st);
            ans += f(dh-1, dw-1, st+1+m);
        }
        
        cout << ans.val() << endl;
    }

    return 0;
}