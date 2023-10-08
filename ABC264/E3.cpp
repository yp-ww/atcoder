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
const ll INF = (ll)1e15;

int main()
{
    int n,m,e;
    cin>>n>>m>>e;
    dsu uf(n+m);
    rep(i,0,m){
        uf.merge(n,n+i);
    }

    vector<int>u(e),v(e);
    rep(i,0,e){
        cin>>u[i]>>v[i];
        u[i]--;
        v[i]--;
    }

    int q;
    cin>>q;
    vector<int>qu(q),ans(q);
    vector<bool> vis(e);
    rep(i,0,q){
        int x;
        cin>>x;
        x--;
        vis[x]=true;
        qu[i] = x;
    }

    rep(i,0,e){
        if (vis[i])continue;
        uf.merge(u[i],v[i]);
    }

    int cnt = 0;
    rep(i,0,n){
        if (uf.same(i,n)) cnt++;
    }

    rrep(i,q-1,0){
        int a = u[qu[i]];
        int b = v[qu[i]];
        ans[i] = cnt;
        if (uf.same(a,n)&&uf.same(b,n))continue;
        if (uf.same(a,n)&&!uf.same(b,n)){
            int pre = uf.size(a);
            uf.merge(a,b);
            int now = uf.size(a);
            cnt+=now-pre;
            continue;
        }
        if (!uf.same(a,n)&&uf.same(b,n)){
            int pre = uf.size(b);
            uf.merge(a,b);
            int now = uf.size(b);
            cnt+=now-pre;
            continue;
        }
        uf.merge(a,b); 
    }
    rep(i,0,q){
        cout << ans[i] << endl;
    }
    
    return 0;
}