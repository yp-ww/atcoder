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
    int M, N;
    cin >> M >> N;
    vector<vector<int>> G(N, vector<int>(M, 0));
    rep(i, 0, N) rep(j, 0, M) cin >> G[i][j];

    vector<int> dn = {0, 0, 1, -1};
    vector<int> dm = {1, -1, 0, 0};

    set<int> st;
    function<int(int, int)> dfs = [&](int n, int m){
        st.insert(n*M + m);
        int res = 0;
        rep(i, 0, 4){
            int n2 = n + dn[i];
            int m2 = m + dm[i];
            if (0 > n2 || N <= n2 || 0 > m2 || M <= m2) continue;
            if (G[n2][m2] == 0) continue;
            if (st.find(n2*M + m2) != st.end()) continue;
            chmax(res, dfs(n2, m2));
        }
        st.erase(n*M + m);
        return res + 1;
    };

    int ans  = 0;
    rep(i, 0, N) rep(j, 0, M){
        if (G[i][j] == 0) continue;
        chmax(ans, dfs(i, j));
    }

    cout << ans << endl;

    return 0;
}
