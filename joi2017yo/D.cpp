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
    vector<int> A(N);
    rep(i, 0, N) {cin >> A[i]; A[i]--;}

    vector<vector<int>> cum(M, vector<int>(N+1, 0));
    rep(i, 0, M) rep(j, 0, N){
        int temp = 0;
        if (A[j] == i) temp = 1;
        cum[i][j+1] = cum[i][j] + temp;
    }

    vector<int> cnt(M, 0);
    rep(i, 0, N) cnt[A[i]]++;

    int INF = 1000000000;
    vector<int> dp(1<<M, INF);
    dp[0] = 0;
    rep(s, 0, 1<<M){
        if (dp[s] == INF) continue;
        
        int done = 0;
        rep(j, 0, M){
            if ((s & (1<<j))) done += cnt[j];
        }

        rep(j, 0, M){
            if ((s & (1<<j))) continue;
            int tot = cum[j][done + cnt[j]] - cum[j][done];
            int dif = cnt[j] - tot;
            chmin(dp[s+(1<<j)], dp[s] + dif);
        }
    }

    int ans = dp[(1<<M)-1];

    cout << ans << endl;


    return 0;
}