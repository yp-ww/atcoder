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
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    int q;
    cin>>q;
    vector<vector<ll>> cum(k, vector<ll>(n+1, 0));

    rep(i,0,n){
       cum[i%k][i+1] = a[i]; 
    }
    rep(i,0,k)rep(j,0,n){
        cum[i][j+1] += cum[i][j];
    }

    rep(_,0,q){
        int l,r;
        cin>>l>>r;
        l--;r--;
        set<ll> st;
        rep(i,0,k){
            ll temp = cum[i][r+1] - cum[i][l];
            st.insert(temp);
        }
        bool flag = false;
        if (st.size()==1) flag = true;
        YesNo(flag);
    }
    return 0;
}