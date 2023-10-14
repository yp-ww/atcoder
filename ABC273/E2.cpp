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
const ll INF = (ll)1e15;

int main()
{
    ll q;
    cin>>q;

    ll pos = 0;
    vector<ll> num(q+1,-1), par(q+1,-1);
    map<ll,ll> mp;
    par[0] = 0;
    rep(i,1,q+1){
        string s;
        cin>>s;
        if (s == "ADD"){
            ll x;
            cin>>x;
            par[i] = pos;
            num[i] = x;
            pos = i;
        }else if(s == "DELETE"){
            pos = par[pos];
        }else if(s == "SAVE"){
            ll y;
            cin>>y;
            mp[y] = pos;
        }else{
            ll z;
            cin>>z;
            pos = mp[z];
        }
        cout << num[pos] << endl;
    }
    return 0;
}