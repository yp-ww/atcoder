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
const ll INF = (ll)1e50;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];

    function<ll(vector<ll>,ll)> dfs = [&](vector<ll> v, ll k){
        if (k==-1) return 0LL;
        vector<ll> s0, s1;
        for (auto idx: v){
            if (a[idx]&(1LL<<k)){
                s1.push_back(idx);
            }else{
                s0.push_back(idx);
            }
        }

        if (s1.size()==0 || s0.size()==0){
            if (s1.size()) return dfs(s1, k-1);
            if (s0.size()) return dfs(s0, k-1);
        }else{
            return min((1LL<<k) + dfs(s1, k-1), (1LL<<k) + dfs(s0, k-1));
        }
        return 0LL;
    };

    vector<ll> s;
    rep(i,0,n) s.push_back((ll)i);
    ll ans = dfs(s, (ll)32);
    cout << ans << endl;
    return 0;
}