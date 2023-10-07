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

ll dp[11][11] = {0};

int main()
{
    int n;
    cin>>n;

    rep(x,1,n+1){
        int k = 0;
        rep(j,1,7){
            if (x/(int)pow(10,j)==0){
                k = j-1;
                break;
            }
        }
        int mi = x%10;
        int ma = x/(int)pow(10,k);
        ma%=10;
        if (mi == 0) continue;
        if (ma == 0) continue;
        dp[mi][ma]++;
    }
    ll ans = 0;
    rep(x,1,n+1){
        int k = 0;
        rep(j,1,7){
            if (x/(int)pow(10,j)==0){
                k = j-1;
                break;
            }
        }
        int mi = x%10;
        int ma = x/(int)pow(10,k);
        ma%=10;
        if (mi == 0) continue;
        if (ma == 0) continue;
        ans+=dp[ma][mi];
    }
    cout << ans << endl;
    

    return 0;
}