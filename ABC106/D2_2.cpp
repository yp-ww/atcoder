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
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> P(505, vector<int>(505, 0));
    rep(i, 0, M){
        int l, r;
        cin >> l >> r;
        P[l][r]++;
    }

    vector<vector<int>> cum(505, vector<int>(505, 0));
    rep(i, 1, 501) rep(j, 1, 501){
        cum[i][j] = P[i][j] + cum[i-1][j] + cum[i][j-1] - cum[i-1][j-1];
    }

    rep(i, 0, Q){
        int p, q;
        cin >> p >> q;
        int ans = cum[q][q] - cum[p-1][q] - cum[q][p-1] + cum[p-1][p-1];
        cout << ans << endl;
    }


    return 0;
}