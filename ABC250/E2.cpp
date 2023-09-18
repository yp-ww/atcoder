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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];

    vector<ll> ha(N+1), hb(N+1);
    set<ll> sa, sb;
    rep(i, 1, N+1){
        ll a = A[i-1];
        ll b = B[i-1];
        if (sa.find(a) == sa.end()){
            ha[i] = ha[i-1] + a * (a+1597) * (a*7841);
            sa.insert(a);
        }else{
            ha[i] = ha[i-1];
        }
        if (sb.find(b) == sb.end()){
            hb[i] = hb[i-1] + b * (b+1597) * (b*7841);
            sb.insert(b);
        }else{
            hb[i] = hb[i-1];
        }
    }
    ll Q;
    cin >> Q;   
    rep(i, 0, Q){
        int x, y;
        cin >> x >> y;
        YesNo(ha[x] == hb[y]);
    }
    return 0;
}