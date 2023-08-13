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
    int H, W;
    cin >> W >> H;
    vector<vector<int>> G(H+2, vector<int>(W+2, 0));
    
    rep(i, 1, H+1) rep(j, 1, W+1) cin >> G[i][j];
    
    vector<int> dh0 = {0, 0, -1, 1, -1, 1};
    vector<int> dw0 = {1, -1, 0, 0, -1, -1};
    vector<int> dh1 = {0, 0, -1, 1, 1, -1};
    vector<int> dw1 = {1, -1, 0, 0, 1, 1};

    dsu d((H+2)*(W+2)+1);
    rep(i, 0, H+2) rep(j, 0, W+2){
        if (i == 0 || i == H+1 || j == 0 || j == W+1){
            d.merge((H+2)*(W+2), i*(W+2)+j);
            continue;
        }
        if (G[i][j] == 1) continue;
        if (i%2 == 0){
            rep(k, 0, 6){
                int h1 = i + dh0[k];
                int w1 = j + dw0[k];
                if (G[h1][w1] == 1) continue;
                d.merge(i*(W+2) + j, h1*(W+2) + w1);
            }
        }else{
            rep(k, 0, 6){
                int h1 = i + dh1[k];
                int w1 = j + dw1[k];
                if (G[h1][w1] == 1) continue;
                d.merge(i*(W+2) + j, h1*(W+2) + w1);
            }            
        }
    }

    int ans = 0;
    rep(i, 0, H+2) rep(j, 0, W+2){
        if (G[i][j] == 0) continue;
        if (i%2 == 0){
            rep(k, 0, 6){
                int h1 = i + dh0[k];
                int w1 = j + dw0[k];
                if (G[h1][w1] == 1) continue;
                if (d.same((H+2)*(W+2), h1*(W+2) + w1)) ans++;
            }            
        }else{
            rep(k, 0, 6){
                int h1 = i + dh1[k];
                int w1 = j + dw1[k];
                if (G[h1][w1] == 1) continue;
                if (d.same((H+2)*(W+2), h1*(W+2) + w1)) ans++;
            }  
        }
    }

    cout << ans << endl;

    return 0;
}