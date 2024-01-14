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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    using P = pair<ll,ll>;
    priority_queue<P, vector<P>, greater<P>> hq;
    rep(i,0,n-k+1){
        hq.push({s[i]-'a', i});
    }
    ll cnt = 0;
    ll pos = n-k+1;
    ll now = -1;
    string ans = "";
    while(cnt<k && !hq.empty()){
        auto [c,p] = hq.top(); hq.pop();
        if (now>=p) continue;
        cnt++;
        now = p;
        if (pos<n){
            hq.push({s[pos]-'a',pos});
            pos++;
        }
        ans += char(c+'a');
    }
    cout << ans << endl;
    
    return 0;
}