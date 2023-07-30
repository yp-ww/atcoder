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
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M));
    rep(i, 0, N) rep(j, 0, M) cin >> A[i][j];

    ll ans = 0;
    rep(i, 0, M){        
        rep(j, i+1, M){
            vector<ll> p(N, 0);
            rep(k, 0, N) p[k] = A[k][i];
            rep(k, 0, N){
                chmax(p[k], A[k][j]);
            }
            ll tot = accumulate(all(p), 0LL);
            chmax(ans, tot);
        }
    }

    cout << ans << endl;

    return 0;
}