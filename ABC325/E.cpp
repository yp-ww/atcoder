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
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<vector<ll>> d(n, vector<ll>(n));
    rep(i,0,n)rep(j,0,n){
        cin>>d[i][j];
    }
    priority_queue<tuple<ll,ll,ll>> hq;
    hq.push({0,0,0});
    hq.push({0,0,1});
    vector<vector<ll>>v(n,vector<ll>(2,INF));
    while (!hq.empty()){
        auto [cost, now, mode] = hq.top(); hq.pop();
        cost *= -1;
        if (v[now][mode]!=INF)continue;
        v[now][mode] = cost;
        rep(nex,0,n){
            if (nex==now)continue;
            if (mode){
                if (v[nex][1] != INF)continue;
                hq.push({-(cost+d[now][nex]*b+c), nex, 1});
            }else{
                if (v[nex][0] == INF)hq.push({-(cost+d[now][nex]*a), nex, 0});
                if (v[nex][1] == INF)hq.push({-(cost+d[now][nex]*b+c), nex, 1});
            }
        }
    }
    cout << min(v[n-1][0], v[n-1][1]) << endl;
    
    return 0;
}