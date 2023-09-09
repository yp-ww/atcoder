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
const ll INF = (ll)1e15;

using mint = modint1000000007;



int main()
{
    int X, Y;
    cin >> X >> Y;
    int MAX = 1000010;
    vector<ll> arr(MAX);
    ll MOD = 1000000007;
    arr[1] = 1LL;
    rep(i, 2, MAX){
        arr[i] = arr[i-1] * i;
        arr[i] %= MOD;
    }
    
    ll ans = 0LL;
    rep(i, 0, MAX){
        int a = i * 1;
        int b = i * 2;
        int c = X - a;
        int d = Y - b;
        if (c < 0 || d < 0) continue;
        if (c != (d * 2)) continue;
        int tot = a + d;
        ll temp = arr[tot];
        if (a != 0) temp *= pow_mod(arr[a], MOD-2, MOD);
        temp %= MOD;
        if (d != 0) temp *= pow_mod(arr[d], MOD-2, MOD);
        temp %= MOD;
        ans += temp;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}