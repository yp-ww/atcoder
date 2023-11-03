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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n;
    cin>>n;
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    set<string> st;
    rep(i,0,n){
        auto s1 = s[i];
        if (st.find(s1)!=st.end())continue;
        reverse(all(s1));
        if (st.find(s1)!=st.end())continue;
        st.insert(s1);
    }
    cout << st.size() << endl;
    return 0;
}