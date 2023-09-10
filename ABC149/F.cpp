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
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    rep(i, 0, N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    vector<mint> pow2(N+10);
    pow2[0] = 1;
    rep(i, 1, N+10){
        pow2[i] = pow2[i-1] * 2;
    }
    
    vector<mint> v(N, 0);
    function<int(int, int)> dfs = [&](int now, int pre){
        v[now] = 0;
        int res = 0;
        mint tot = 0;
        for (auto nex: G[now]){
            if (nex == pre) continue;
            int temp = dfs(nex, now);
            res += temp;
            tot += pow2[temp] - 1;
        }

        //  親側の個数
        int cnt_pre = N - res - 1;
        tot += pow2[cnt_pre] - 1;
        v[now] = tot;

        res++; 
        return res;
    };

    dfs(0, -1);

    mint ans = 0;
    rep(i, 0, N){
        mint tot = pow2[N-1];
        mint cnt = tot;
        cnt -= 1;
        cnt -= v[i];
        ans += cnt / pow2[N];
    }
    cout << ans.val() << endl;

    return 0;
}