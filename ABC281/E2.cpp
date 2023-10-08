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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    multiset<ll> apl, rem;
    vector<ll>temp;
    rep(i,0,m){
        temp.push_back(a[i]);
    }
    sort(all(temp));
    ll ans = 0;
    rep(i,0,k){
        apl.insert(temp[i]);
        ans += temp[i];
    }
    rep(i,k,m) rem.insert(temp[i]);
    cout << ans << endl;
    rep(i,1,n-m+1){
        ll de = a[i-1];
        ll ad = a[i+m-1];
        if (apl.find(de) != apl.end()){
            auto ide = apl.lower_bound(de);
            apl.erase(ide);
            ans -= de;
            rem.insert(ad);
            auto itr = rem.begin();
            ll x = *itr;
            apl.insert(x);
            ans += x;
            auto ix = rem.lower_bound(x);
            rem.erase(ix);
        }else{
            auto ide = rem.lower_bound(de);
            rem.erase(ide);
            apl.insert(ad);
            auto itr = apl.end();
            itr--;
            ll x = *itr;
            if (x==ad){
                rem.insert(ad);
                auto ix = apl.lower_bound(x);
                apl.erase(ix);
            }else{
                ans -= x;
                ans += ad;
                rem.insert(x);
                auto ix = apl.lower_bound(x);
                apl.erase(ix);
            }
        }
        cout << ans << endl;
    }
    rep(i,0,n){

    }
    return 0;
}