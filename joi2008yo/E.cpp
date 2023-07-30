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
    int R, C;
    cin >> R >> C;
    vector<vector<int>> A(R, vector<int>(C));
    rep(i, 0, R) rep(j, 0, C) cin >> A[i][j];

    int ans = 0;
    rep(k, 0, 1<<R){
        int tot = 0;
        rep(j, 0, C){
            int cnt = 0;
            rep(i, 0, R){
                int a = A[i][j];
                if ((k>>i) & 1) a = (a + 1) % 2;
                if (!a) cnt++;  
            }
            tot += max(R-cnt, cnt);
        }
        chmax(ans, tot);
    }
    cout << ans << endl;

    return 0;
}