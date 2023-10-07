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
    vector<int>a(n);
    rep(i,0,n)cin>>a[i];
    vector<int> cnt(4);
    rep(i,0,n)cnt[a[i]-1]++;
    
    vector<vector<int>> g(4 ,vector<int>(4,0));
    int left = 0;
    rep(i,0,4){
        rep(j,left,left+cnt[i]){
            g[i][a[j]-1]++; 
        }
        left+=cnt[i];
    }

    ll ans = 0;
    rep(i,0,4) rep(j,0,4){
        if(i < j){
            int dif = min(g[i][j], g[j][i]);
            ans += dif;
            g[i][j] -= dif;
            g[j][i] -= dif;
        }
    }

    rep(i,0,4)rep(j,0,4)rep(k,0,4){
        if (i==j||j==k||k==i) continue;
        int dif = min({g[i][j],g[j][k],g[k][i]});
        ans += dif * 2;
        g[i][j] -= dif;
        g[j][k] -= dif;
        g[k][i] -= dif;
    }

    rep(i,0,4)rep(j,0,4)rep(k,0,4)rep(l,0,4){
        if (i==j||j==k||k==i||i==l||j==l||k==l) continue;
        int dif = min({g[i][j],g[j][k],g[k][l],g[l][i]});
        ans += dif * 3;
        g[i][j] -= dif;
        g[j][k] -= dif;
        g[k][l] -= dif;
        g[l][i] -= dif;
    }

    cout << ans << endl;

    return 0;
}