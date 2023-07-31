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
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    rep(i, 0, N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> dp(N, 0LL);
    rep(i, 0, Q){
        int p, x;
        cin >> p >> x;
        p--;
        dp[p] += (ll)x;
    }

    vector<bool> v(N);
    function<void(int)> dfs = [&](int x){
        v[x] = true;
        for (auto nex: G[x]){
            if (v[nex]) continue;
            dp[nex] += dp[x];
            dfs(nex);
        }
        return ;
    };

    dfs(0);

    rep(i, 0, N){
        cout << dp[i] << " ";
    }
    cout << endl;

    return 0;
}