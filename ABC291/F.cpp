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
    int n,m;
    cin>>n>>m;
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    vector<vector<int>>to(n),ba(n);
    rep(i,0,n){
        rep(j,0,m){
            if(s[i][j]=='0')continue;
            if(i+j+1<n)to[i].push_back(i+j+1);
            if(i+j+1<n)ba[i+j+1].push_back(i);
        }
    }
    queue<int> q;
    q.push(n-1);
    vector<int>v(n,-1);
    v[n-1]=0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for (auto nex:ba[now]){
            if (v[nex]!=-1)continue;
            v[nex]=v[now]+1;
            q.push(nex);
        }
    }
    q.push(0);
    vector<int>x(n,-1);
    x[0]=0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for (auto nex:to[now]){
            if (x[nex]!=-1)continue;
            x[nex]=x[now]+1;
            q.push(nex);
        }
    }
    rep(k,1,n-1){
        int ans = 100000000;
        rep(a,k-m+1,k){
            if(a<0)continue;
            if(x[a]==-1)continue;
            for(auto nex:to[a]){
                if(nex<=k)continue;
                if(v[nex]==-1)continue;
                chmin(ans,x[a]+v[nex]);
            }
        }
        if (ans==100000000){
            cout << -1 << endl;
        }else{
            cout << ans+1 << endl;
        }
        
    }
    return 0;
}