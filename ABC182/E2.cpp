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

ll g[2000][2000][4] = {0};

int main()
{
    int h,w,n,m;
    cin>>h>>w>>n>>m;

    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        rep(j,0,4){
            g[a][b][j] = 1;
        }
    }
    rep(i,0,m){
        int c,d;
        cin>>c>>d;
        rep(j,0,4){
            g[c][d][j] = -INF;
        }
    }

    vector<pair<int,int>> d= {{0,1},{1,0},{0,-1},{-1,0}};
    rep(i,1,h+1) rep(j,1,w+1){
        rep(k,0,4){
            if (g[i][j][k]!=1) continue;
            auto [dh,dw] = d[k];
            int ddh = dh;
            int ddw = dw;
            while (1){
                if (g[i+ddh][j+ddw][k] != 0) break;
                if (i+ddh <= 0 || i+ddh > h) break;
                if (j+ddw <= 0 || j+ddw > w) break;
                g[i+ddh][j+ddw][k] = 1;
                ddh += dh;
                ddw += dw;
            }
        }
    }

    int ans = 0;
    rep(i,1,h+1)rep(j,1,w+1){
        bool flag = false;
        rep(k,0,4){
            if (g[i][j][k] > 0) flag = true; 
        }
        if (flag) ans++;
    }
    cout << ans << endl;

    return 0;
}