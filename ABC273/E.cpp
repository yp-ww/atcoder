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
    int q;
    cin >> q;
 
    vector<ll> par(q+1), cnt(q+1);
    par[0] = 0;
    vector<ll> ans(q+1);
    map<ll,int> mp;
    int last = 0;
    ans[0] = -1;
    rep(i,1,q+1){
        string s;
        cin >> s;
        if (s == "ADD"){
            ll x;
            cin>>x;
            par[i] = i-1;
            last = i;
            ans[i] = x;
            cnt[i]++;
        }else if (s == "DELETE"){
            int pos = i-1;
            while (1){
                if (pos <= 0) break;
                if (cnt[pos] >= 1){
                    pos = par[pos];
                    break;
                }
                pos = par[pos];
            }
            par[i] = pos;
            ans[i] = ans[par[i]];
            last = i;
        }else if (s == "SAVE"){
            ll y;
            cin>>y;
            mp[y] = i;
            par[i] = last;
            ans[i] = ans[par[i]];
        }else{
            ll z;
            cin>>z;
            last = i;
            par[i] = mp[z];
            ans[i] = ans[par[i]];
        }
    }
    rep(i,1,q+1){
        cout << ans[i] << endl;
    }

    return 0;
}