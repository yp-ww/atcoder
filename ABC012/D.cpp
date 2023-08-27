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
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> dis(N, vector<ll>(N, INF));
    rep(i, 0, N){
        dis[i][i] = 0LL;
    }

    rep(i, 0, M){
        int a, b;
        ll t;
        cin >> a >> b >> t;
        a--; b--;
        dis[a][b] = t;
        dis[b][a] = t;
    }
    
    rep(k, 0, N) rep(i, 0, N) rep(j, 0, N){
        chmin(dis[i][j], dis[i][k] + dis[k][j]);
    }

    ll ans = INF;
    rep(i, 0, N){
        ll temp = 0;
        rep(j, 0, N){
            if (i == j) continue;
            chmax(temp, dis[i][j]);
        }
        chmin(ans, temp);
    }
    cout << ans << endl;

    
    return 0;
}