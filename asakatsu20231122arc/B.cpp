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

map<long long, int> primeFactorization(long long n){
    map<long long, int> res;
    for (long long i=2; i*i<=n; i++){
        while (n % i == 0){ res[i]++; n /= i;}
    }
    if(n != 1) res[n] = 1;
    return res;
}

int main()
{
    ll n;
    cin>>n;
    vector<ll>x(n);
    rep(i,0,n)cin>>x[i];
    vector<ll>cnt(100);
    rep(i,0,n){
        map<ll, int> mp = primeFactorization(x[i]);
        for (auto [key,c]: mp){
            cnt[key]++;
        }
    }
    ll ans = 1;
    vector<bool> v(n);
    rep(i,2,51){
        if (cnt[i]==0) continue;
        if (find(all(v), false) == v.end()) break;
        bool flag = false;
        rep(j,0,n){
            if (v[j])continue;
            if (x[j]%i)continue;
            flag = true;
            v[j] = true;
        }
        if (flag) ans *= i;
    }

    cout << ans << endl;

    return 0;
}