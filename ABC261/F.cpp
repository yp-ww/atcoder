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

int op(int a, int b){ return a+b; };
int e(){ return 0; };

int main()
{
    int n;
    cin>>n;
    vector<int>c(n),x(n);
    rep(i,0,n)cin>>c[i];
    rep(i,0,n)cin>>x[i];

    int MAX = 300010;
    vector<int> cnt(MAX);
    rep(i,0,n) cnt[x[i]]++;

    segtree<int,op,e> seg(MAX);
    rep(i,0,MAX){
        seg.set(i, cnt[i]);
    }
    
    vector<vector<int>> gr(MAX);
    ll ans = 0;
    rep(i,0,n){
        ans += (ll)seg.prod(0, x[i]);
        gr[c[i]].push_back(x[i]);
        seg.set(x[i], seg.get(x[i])-1);
    }
    
    segtree<int,op,e> seg2(MAX);
    rep(i,0,MAX){
        if (gr[i].size() == 0) continue;
        for (auto z: gr[i]){
            ans -= (ll)seg2.prod(z+1, MAX);
            seg2.set(z, seg2.get(z)+1);
        }
        for (auto z: gr[i]){
            seg2.set(z, 0);
        }
    }
    cout << ans << endl;

    return 0;
}