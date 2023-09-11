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

    vector<vector<ll>> G(N+10, vector<ll>(N+10));
    rep(i, 0, M){
        ll a, b, x;
        cin >> a >> b >> x;
        a--; b--;
        G[a][b]++;
        G[a][b+1]--;
        G[a+x+1][b]--;
        G[a+x+2][b+1]++;
        G[a+x+1][b+x+2]++;
        G[a+x+2][b+x+2]--;
    }

    rep(i, 0, N+5) rep(j, 0, N+5){
        G[i+1][j+1] += G[i][j];
    }

    rep(i, 0, N+5) rep(j, 0, N+5){
        G[i+1][j] += G[i][j];
    }

    rep(i, 0, N+5) rep(j, 0, N+5){
        G[i][j+1] += G[i][j];
    }

    ll cnt = 0;
    rep(i, 0, N) rep(j, 0, i+1){
        if (G[i][j] >= 1) cnt++;
    }
    cout << cnt << endl;

    return 0;
}