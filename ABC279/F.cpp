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
    int n,q;
    cin>>n>>q;

    vector<int> par(n+q+10,-1), inv(n+1,-1);
    rep(i,1,n+1){
        inv[i] = i;
        par[i] = i;
    }

    dsu d(n+q+10);

    int cnt = n;
    rep(i,0,q){
        int c;
        cin>>c;
        if (c==1){
            int x,y;
            cin>>x>>y;
            if (inv[y]==-1)continue;
            if (inv[x]==-1){
                par[d.leader(inv[y])] = x;
                inv[x] = d.leader(inv[y]);
                inv[y] = -1;
            }else{
                d.merge(inv[x], inv[y]);
                par[d.leader(inv[x])] = x;
                inv[x] = d.leader(inv[x]);
                inv[y] = -1;
            }
            
        }else if(c==2){
            int x;
            cin>>x;
            int k = cnt+1;
            cnt++;
            if (inv[x]==-1){
                par[k] = x;
                inv[x] = k; 
            }else{
                d.merge(inv[x], k);
                par[d.leader(inv[x])] = x;
                inv[x] = d.leader(inv[x]);
            }
        }else{
            int x;
            cin>>x;
            int ld = d.leader(x);
            cout << par[ld] << endl;
        }
    }

    return 0;
}