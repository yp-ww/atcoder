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
    int s,t,m;
    cin>>s>>t>>m;

    vector<vector<int>> g(s+t);
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> vis(t, vector<int>(t,-1));
    rep(i,0,s){
        for (auto t1: g[i]){
            for (auto t2: g[i]){
                if (t1 >= t2) continue;
                if (vis[t1-s][t2-s] == -1){
                    vis[t1-s][t2-s] = i;
                }else{
                    cout << vis[t1-s][t2-s]+1 << " " << i+1 << endl;
                    cout << t1+1 << " " << t2+1 << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << -1 << endl;

    return 0;
}