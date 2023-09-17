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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    ll lc = 1;
    rep(i, 0, N) lc = lcm(lc, A[i]/2);

    bool ng = false;
    rep(i, 0, N){
        if ((lc/(A[i]/2))%2 == 0) ng = true;
    }

    if (ng){
        cout << 0 << endl;
    }else{
        cout << M/lc - M/(lc*2) << endl;  
    }
    
    
    return 0;
}