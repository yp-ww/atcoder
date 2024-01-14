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
const ll INF = (ll)1e18+10;

int main()
{
    ll n;
    cin>>n;
    string ans = "";
    if (n==1){
        cout << 0 << endl;
        return 0;
    }
    n--;
    while(n){
        ans += char('0' + n%5);
        n /= 5;
    }
    reverse(all(ans));
    string ans2 = "";
    rep(i,0,ans.size()){
        ans2 += char('0' + (ans[i]-'0')*2);
    }
    cout << ans2 << endl;

    return 0;
}