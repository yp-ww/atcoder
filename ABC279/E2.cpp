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
    vector<int> A(M+1);
    rep(i, 1, M+1) cin >> A[i];

    vector<int> B(N+1);
    rep(i, 1, N+1) B[i] = i;
    rep(i, 1, M+1){
        int x = A[i];
        int y = A[i]+1;
        swap(B[x], B[y]);
    }

    vector<int> C(N+1);
    rep(i, 1, N+1){
        C[B[i]] = i;
    }

    vector<int> ans(M+1);
    rrep(i, M, 1){
        int x = B[A[i]];
        int y = B[A[i]+1];
        swap(B[A[i]], B[A[i]+1]);
        if (x == 1){
            ans[i] = C[y];
        }else if (y == 1){
            ans[i] = C[x];
        }else{
            ans[i] = C[1];
        }
    }
    rep(i, 1, M+1){
        cout << ans[i] << endl;
    }

    return 0;
}