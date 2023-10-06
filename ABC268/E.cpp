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
    vector<int>p(n);
    rep(i,0,n)cin>>p[i];

    vector<int> pos(n);
    rep(i,0,n) pos[p[i]] = i;
    vector<ll> cum(2*n+1);

    ll init = 0;
    rep(i,0,n){
        int now = pos[i];
        int dis = min((i-now+n) % n, (now-i+n) % n);
        init += dis;
        bool left = false;
        if (i+dis == now || i+dis == now+n){
            left = true;
        }
        if (n%2){
            if (left){
                cum[0]++;
                cum[n/2-dis]--;
                cum[n/2-dis+1]--;
                cum[n/2-dis+1+n/2]++;
                cum[n/2-dis+1+n/2]++;
            }else{
                cum[0]--;
                cum[dis]++;
                cum[dis]++;
                cum[dis+n/2]--;
                cum[dis+n/2+1]--;
            }
        }else{
            if (left){
                cum[0]++;
                cum[n/2-dis]--;
                cum[n/2-dis]--;
                cum[n/2-dis+n/2]++;
                cum[n/2-dis+n/2]++;
            }else{
                cum[0]--;
                cum[dis]++;
                cum[dis]++;
                cum[dis+n/2]--;
                cum[dis+n/2]--;
            }            
        }        
    }
    rep(i,0,n) cum[i+1] += cum[i];
    rep(i,0,n) cum[i+1] += cum[i];
    ll ans = init;
    rep(i,0,n){
        chmin(ans, init + cum[i]);
    }
    cout << ans << endl;

    return 0;
}