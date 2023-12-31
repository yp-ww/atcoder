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
    queue<pair<ll,string>> q;
    q.push({0,""});
    vector<string>ans;
    while(!q.empty()){
        auto [now, s] = q.front(); q.pop();
        if (now<0) continue;
        if (s.size()==n){
            if (now==0) ans.push_back(s);
            continue;
        }
        q.push({now+1, s+'('});
        q.push({now-1, s+')'});
    }
    sort(all(ans));
    for (auto a: ans) cout << a << endl;
    return 0;
}