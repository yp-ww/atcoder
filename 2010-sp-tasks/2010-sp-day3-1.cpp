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
    int N, M, K;
    cin >> N >> M >> K;
    // vector<vector<pair<int, int>>> G(N);
    set<tuple<int, int, int>> st;
    rep(i, 0, M){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        // G[a].push_back({b, c});
        // G[b].push_back({a, c});
        st.insert({c, a, b});
    }

    dsu uf(N);
    int ans = 0;
    int cnt = 0;
    for (auto [cost, a, b]: st){
        if (cnt >= N-K) break;
        if (uf.same(a, b)) continue;
        uf.merge(a, b);
        ans += cost;
        cnt++;
    }
    cout << ans << endl;





    return 0;
}