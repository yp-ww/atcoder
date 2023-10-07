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
    int n,k;
    cin>>n>>k;
    vector<int>p(n);
    rep(i,0,n)cin>>p[i];
    vector<int> par(n+1), cnt(n+1), ans(n+1, -1);
    vector<vector<int>>gr(n+1);
    set<int> st;
    rep(i,0,n){
        auto itr = st.lower_bound(p[i]);
        if (itr == st.end()){
            st.insert(p[i]);
            par[p[i]] = p[i];
            cnt[par[p[i]]]++;
            gr[par[p[i]]].push_back(p[i]);
        }else{
            int x = *itr;
            st.erase(x);
            st.insert(p[i]);
            par[p[i]] = par[x];
            cnt[par[p[i]]]++;
            gr[par[p[i]]].push_back(p[i]);
        }
        if (cnt[par[p[i]]] == k){
            st.erase(p[i]);
            for(auto y: gr[par[p[i]]]){
                ans[y] = i+1;
            }
        }
    }
    rep(i,1,n+1){
        cout << ans[i] << endl;
    }
    return 0;
}