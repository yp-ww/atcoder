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
    string s;
    cin>>s;
    vector<string>arr;
    rep(i,0,10000000){
        if (i*i>=pow(10LL, n)) break;
        string t = to_string(i*i);
        while (t.size()!=n){
            t = '0' + t;
        }
        arr.push_back(t);
    }
    vector<ll>cnt(10);
    rep(i,0,n){
        cnt[s[i]-'0']++;
    }
    ll ans = 0;
    for (auto x: arr){
        vector<ll> temp(10);
        rep(i,0,n){
            temp[x[i]-'0']++;
        }
        if (temp==cnt) ans++;
    }
    cout << ans << endl;


    return 0;
}