#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)3e15;

int main()
{
    ll m;
    cin>>m;
    vector<string> s(3);
    rep(i,0,3) cin>>s[i];
    ll ans = INF;
    sort(all(s));
    do {
        rep(i,0,10){
            ll cnt = 0;
            vector<bool>vis(3);
            rep(t,0,m*5){
                rep(k,0,3){
                    if (vis[k])continue;
                    if (s[k][t%m] == char('0'+i)){
                        cnt++;
                        vis[k] = true;
                        break;
                    }
                }
                if (cnt==3){
                    chmin(ans, t);
                    break;
                }
            }
        }
    }while (next_permutation(all(s)));

    if(ans==INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}