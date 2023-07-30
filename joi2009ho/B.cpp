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
    ll D;
    cin >> D;
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    rep(i, 1, N) cin >> A[i];
    rep(i, 0, M) cin >> B[i];
    A.push_back(D);
    sort(all(A));

    ll ans = 0;
    rep(i, 0, M){
        ll b = B[i];
        if (b == 0) continue;
        int idx = lower_bound(all(A), b) - A.begin();
        ll x = A[idx-1];
        ll y = A[idx];
        ans += min(abs(x-b), abs(y-b));
    }

    cout << ans << endl;




    return 0;
}