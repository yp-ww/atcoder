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
    ll N, L;
    cin >> N >> L;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    ll tot = 0LL;
    rep(i, 0, N) tot += A[i];
    if (tot != L){
        A.push_back(L-tot);
        N++;
    }

    priority_queue<ll> hq;
    rep(i, 0, N){
        hq.push(-A[i]);
    }
    ll ans = 0LL;
    while (!hq.empty()){
        auto p = hq.top(); hq.pop();
        p *= -1;
        if (hq.empty()) break;
        auto p2 = hq.top(); hq.pop();
        p2 *= -1;
        ll len = p + p2;
        ans += len;
        hq.push(-len);
    }

    cout << ans << endl;

    return 0;
}