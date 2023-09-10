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
    ll H, W, K, V;
    cin >> H >> W >> K >> V;

    vector<vector<ll>> A(H, vector<ll>(W, 0));
    rep(i, 0, H) rep(j, 0, W) cin >> A[i][j];

    vector<vector<ll>> cum(H+1, vector<ll>(W+1, 0));
    rep(i, 0, H) rep(j, 0, W){
        cum[i+1][j+1] = cum[i][j+1] + cum[i+1][j] - cum[i][j] + A[i][j];
    }

    ll ans = 0;
    rep(i, 0, H) rep(j, 0, W){
        rep(k, 0, W){
            if (j + k >= W) break;
            int l = -1;
            int r = H;
            while (r - l > 1){
                int mid = (l + r) / 2;
                bool flag = false;
                int nw = j + k;
                int nh = i + mid;
                if (nh >= H){
                    r = mid;
                    continue;
                }
                ll temp = cum[nh+1][nw+1] - cum[nh+1][j] - cum[i][nw+1] + cum[i][j];
                ll s = (k+1) * (mid+1);
                
                if (temp + s*K <= V){
                    flag = true;
                }else{
                    flag = false;
                }

                if (flag){
                    l = mid;
                }else{
                    r = mid;
                }
            }
            int nw = j + k;
            int nh = i + l;
            ll temp = cum[nh+1][nw+1] - cum[nh+1][j] - cum[i][nw+1] + cum[i][j];
            ll s = (k+1) * (l+1);
            if (temp + s*K <= V) chmax(ans, s);      
        }
    }
    cout << ans << endl;

    return 0;
}