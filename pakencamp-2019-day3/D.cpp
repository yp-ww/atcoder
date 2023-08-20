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
const int INF = (int)1e9;

int main()
{
    int N;
    cin >> N;
    vector<string> S(5);
    rep(i, 0, 5) cin >> S[i];

    vector<int> R(N), B(N), W(N);
    rep(j, 0, N){
        rep(i, 0, 5){
            if (S[i][j] == 'R') R[j]++;
            if (S[i][j] == 'B') B[j]++;
            if (S[i][j] == 'W') W[j]++;
        }
    }

    vector<int> dpR(N, INF), dpB(N, INF), dpW(N, INF);
    dpR[0] = 5 - R[0];
    dpB[0] = 5 - B[0];
    dpW[0] = 5 - W[0];
    rep(i, 0, N-1){
        chmin(dpR[i+1], dpB[i] + 5 - R[i+1]);
        chmin(dpR[i+1], dpW[i] + 5 - R[i+1]);
        chmin(dpB[i+1], dpR[i] + 5 - B[i+1]);
        chmin(dpB[i+1], dpW[i] + 5 - B[i+1]);
        chmin(dpW[i+1], dpR[i] + 5 - W[i+1]);
        chmin(dpW[i+1], dpB[i] + 5 - W[i+1]);
    }

    int ans = INF;
    chmin(ans, dpR[N-1]);
    chmin(ans, dpB[N-1]);
    chmin(ans, dpW[N-1]);

    cout << ans << endl;

    return 0;
}