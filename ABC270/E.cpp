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

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    ll tot = 0LL;
    rep(i, 0, N) tot += A[i];

    ll l = 0LL;
    ll r = INF;
    while (r-l>1){
        ll mid = (l+r)/2;
        ll cnt = 0;
        rep(i, 0, N){
            cnt += min(A[i], mid);
        }
        if (cnt > K){
            r = mid;
        }else{
            l = mid;
        }
    }

    ll amari = K;
    vector<ll> ans(N);
    rep(i, 0, N){
        amari -= min(A[i], l);
        ans[i] = max(A[i]-l, 0LL);
    }

    rep(i, 0, N){
        if (amari > 0 && ans[i] > 0){
            ans[i] -= 1LL;
            amari--;
        }
    }

    rep(i, 0, N){
        if (i == N-1){
            cout << ans[i] << endl;
        }else{
            cout << ans[i] << " ";
        }
    }

    return 0;
}