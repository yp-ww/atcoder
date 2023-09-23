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

using mint = modint998244353;

int main()
{
    int q,k;
    cin>>q>>k;
    
    vector<mint> dp(5001);
    dp[0]=1;
    rep(i,0,q){
        char c;
        int x;
        cin>>c>>x;
        if (c=='+'){
            rrep(j,5000,x){
                dp[j]+=dp[j-x];
            }
        }else{
            rep(j,x,5001){
                dp[j]-=dp[j-x];
            }
            
        }
        cout << dp[k].val() << endl;
    }

    return 0;
}