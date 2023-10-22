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
const ll INF = (ll)3e18;

using P = pair<ll,ll>;

int main()
{
    ll n;
    cin>>n;
    
    vector<P> arr;
    rep(i,0,n){
        ll t,d;
        cin>>t>>d;
        arr.push_back({t, t+d});
    }
    sort(all(arr));
    arr.push_back({INF+7,INF+7});
    priority_queue<ll,vector<ll>,greater<ll>> hq;
    ll now = 0;
    ll ans = 0;
    rep(i,0,n){
        now = arr[i].first;
        hq.push(arr[i].second);
        while (!hq.empty() && now < arr[i+1].first){
            ll t = hq.top(); hq.pop();
            if (now <= t){
                now++;
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}