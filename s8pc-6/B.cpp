#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
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
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, 0, N) cin >> A[i] >> B[i];
    vector<ll> st, gl;
    rep(i, 0, N){
        st.push_back(A[i]);
        st.push_back(B[i]);
        gl.push_back(A[i]);
        gl.push_back(B[i]);
    }
    ll ans = INF;
    for (auto s: st){
        for (auto g: gl){
            ll cost = 0;
            rep(i, 0, N){
                cost += abs(s - A[i]);
                cost += abs(A[i]-B[i]);
                cost += abs(g - B[i]);
            }
            chmin(ans, cost);
        }
    }
    cout << ans << endl;
    return 0;
}