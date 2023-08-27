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
    vector<vector<pair<int, ll>>> G(N);
    rep(i, 0, M){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    ll ans = 0;
    vector<bool> v(N, false);
    // set<int> st;
    function<void(int, ll)> dfs = [&](int now, ll d){
        // st.insert(now);
        v[now] = true;
        for(auto [nex, cost]: G[now]){
            // if (st.find(nex) != st.end()) continue;
            if (v[nex]) continue;
            dfs(nex, d + cost);
            chmax(ans, d + cost);
        }
        // st.erase(now);
        v[now] = false;
    };

    rep(i, 0, N){
        dfs(i, 0);
    }

    cout << ans << endl;

    return 0;
}