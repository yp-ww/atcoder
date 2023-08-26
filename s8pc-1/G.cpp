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
const ll INF = (ll)1e30;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<tuple<int, ll, ll>>> G(N); 
    rep(i, 0, M){
        int s, t;
        ll d, time;
        cin >> s >> t >> d >> time;
        s--; t--;
        G[s].push_back(make_tuple(t, d, time));
        G[t].push_back(make_tuple(s, d, time));
    }

    vector<vector<ll>> dp(1<<N, vector<ll>(N, INF));
    vector<vector<ll>> num(1<<N, vector<ll>(N));
    dp[0][0] = 0;
    num[0][0] = 1;

    rep(s, 0, 1<<N) rep(now, 0, N){
        if (num[s][now] == 0) continue;
        for (auto [nex, d, time]: G[now]){
            if (s & (1<<nex)) continue;
            ll t = dp[s][now] + d;
            if (t > time) continue;
            if (dp[s+(1<<nex)][nex] > t){
                dp[s+(1<<nex)][nex] = t;
                num[s+(1<<nex)][nex] = num[s][now];
            }else if (dp[s+(1<<nex)][nex] == t){
                num[s+(1<<nex)][nex] += num[s][now];
            }
        }
    }

    if (num[(1<<N)-1][0] == 0){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << dp[(1<<N)-1][0] << " " << num[(1<<N)-1][0] << endl;
    } 
    return 0;
}