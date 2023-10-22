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
    ll n;
    cin>>n;
    string t;
    cin>>t;
    vector<string> s(n);
    rep(i,0,n) cin>>s[i];

    vector<ll>ans;
    rep(i,0,n){
        if (t.size()==s[i].size()){
            ll cnt = 0;
            rep(j,0,t.size()){
                if (t[j]!=s[i][j]) cnt++;
            }
            if (cnt<=1) ans.push_back(i+1);

        }else if(t.size() == 1+s[i].size()){
            ll pos = t.size()-1;
            rep(j,0,s[i].size()){
                if (t[j]!=s[i][j]){
                    pos = j;
                    break;
                }
            }
            ll cnt = 0;
            rep(j,0,s[i].size()){
                if (pos<=j){
                    if (t[j+1]!=s[i][j])cnt++;
                }else{
                    if (t[j]!=s[i][j])cnt++;
                }
            }
            if (cnt==0) ans.push_back(i+1);

        }else if(t.size()+1 == s[i].size()){
            ll pos = s[i].size()-1;
            rep(j,0,t.size()){
                if (t[j]!=s[i][j]){
                    pos = j;
                    break;
                }
            }
            ll cnt = 0;
            rep(j,0,t.size()){
                if (pos<=j){
                    if (t[j]!=s[i][j+1])cnt++;
                }else{
                    if (t[j]!=s[i][j])cnt++;
                }
            }
            if (cnt==0) ans.push_back(i+1);
        }
    }

    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x << endl;
    }

    return 0;
}