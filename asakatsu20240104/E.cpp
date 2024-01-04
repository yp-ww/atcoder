#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e18+10;

int main()
{
    string s;
    cin>>s;

    ll n = s.size();
    rep(i,0,n){
        if (i+3>n)break;
        set<char> st;
        rep(j,i,i+3){
            st.insert(s[j]);
        }
        if (st.size()!=3){
            cout << i+1 << " " << i+1+2 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}