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
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N);
    rep(i, 0, N) cin >> P[i];

    P.push_back(0LL);
    set<ll> st;
    rep(i, 0, N+1) rep(j, 0, N+1){
        if (P[i] + P[j] > M) continue;
        st.insert(P[i] + P[j]);
    }

    ll ans = 0LL;
    for (auto x: st){
        ll y = M - x;
        if (y == 0) { ans = M; break; }
        auto itr = st.lower_bound(y);
        itr--;
        ll z = *itr;
        chmax(ans, x+z);
    }

    cout << ans << endl;
    
    return 0;
}