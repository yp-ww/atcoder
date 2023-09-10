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
    int M, N, K;
    cin >> M >> N >> K;
    vector<string> S(M);
    rep(i, 0, M) cin >> S[i];

    map<int, char> mp = {{0, 'J'}, {1, 'O'}, {2, 'I'}};
    vector<vector<vector<int>>> cum(M+1, vector<vector<int>>(N+1, vector<int>(3, 0)));

    rep(i, 0, M) rep(j, 0, N) rep(k, 0, 3){
        int s = 0;
        if (mp[k] == S[i][j]) s = 1;
        cum[i+1][j+1][k] = s + cum[i][j+1][k] + cum[i+1][j][k] - cum[i][j][k];
    }

    rep(i, 0, K){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        rep(k, 0, 3){
            if (k !=0 ) cout << " ";
            int ans = cum[c][d][k] - cum[c][b-1][k] - cum[a-1][d][k] + cum[a-1][b-1][k];
            cout << ans;
        }
        cout << endl;
    }

    return 0;
}