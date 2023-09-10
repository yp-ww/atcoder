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
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    rep(i, 1, N) cin >> P[i];
    vector<ll> cum(N);
    rep(i, 1, N){
        cum[i] = cum[i-1] + P[i];
    }

    vector<int> Q(M);
    rep(i, 0, M) cin >> Q[i];

    int now = 0;
    ll ans = 0LL;
    rep(i, 0, M){
        int nex = now + Q[i];
        if (nex < now){
            ans += abs(cum[now] - cum[nex]);
        }else{
            ans += abs(cum[nex] - cum[now]);
        }
        now = nex;
    }
    cout << ans % 100000 << endl;

    return 0;
}