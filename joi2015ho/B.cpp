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

int N;
ll A[2020];
ll dp[2020][2020];
bool flag[2020][2020];

ll f(int l, int r, int mode){
    l = (N + l%N)%N;
    r = (N + r%N)%N;

    if (flag[l][r]) return dp[l][r];
    if (l == r){
        if (mode){
            return A[l];
        }else{
            return 0;
        }
    }
    
    if (mode == 0){
        if (A[l] < A[r]){
            return f(l, r-1, 1);
        }else{
            return f(l+1, r, 1);
        }
    }
    
    flag[l][r] = true;
    return dp[l][r] = max(f(l+1, r, 0) + A[l], f(l, r-1, 0) + A[r]);

}

int main()
{
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) rep(j, 0, N){
        dp[i][j] = 0;
        flag[i][j] = false;
    }

    ll ans = 0;
    rep(i, 0, N){
        chmax(ans, f(i+1, i-1, 0) + A[i]);
    }

    cout << ans << endl;

    return 0;
}