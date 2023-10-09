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
    ll w;
    cin>>w;
    vector<ll> ans;
    ll cnt = 0;
    rep(i,1,100){
        cnt+=3;
        ans.push_back(i);
        ans.push_back(i*100);
        ans.push_back(i*10000);
    }
    sort(all(ans));
    cout << cnt << endl;
    for (auto x: ans){
        cout << x << endl;
    }
    
    return 0;
}