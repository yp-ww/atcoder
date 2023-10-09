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
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    rep(i,0,n)cin>>s[i];
    
    vector<vector<int>> to(n), ba(n);
    rep(i,0,n){
        rep(j,0,m){
            if (s[i][j] == '1'){
                to[i].push_back(i+j+1);
                ba[i+j+1].push_back(i);
            }
        }
    }
    priority_queue<pair<int,int>> hq;
    hq.push({-0, 0});
    vector<int> v(n,-1);
    while (!hq.empty()){
        auto [cost, now] = hq.top(); hq.pop();
        if (v[now]!=-1) continue;
        cost *= -1;
        v[now] = cost;
        for (auto nex: to[now]){
            if (v[nex]!=-1)continue;
            hq.push({-(cost+1), nex});
        }
    }

    hq.push({-0, n-1});
    vector<int> v2(n,-1);
    while (!hq.empty()){
        auto [cost, now] = hq.top(); hq.pop();
        if (v2[now]!=-1) continue;
        cost *= -1;
        v2[now]=cost;
        for (auto nex: ba[now]){
            if (v2[nex]!=-1)continue;
            hq.push({-(cost+1), nex});
        }
    }

    const int ma = 100000000;
    rep(k,1,n-1){
        int ans = ma;
        rep(i, k-m+1, k){
            if (i<0) continue;
            if (v[i] == -1) continue;
            for (auto nex: to[i]){
                if (nex<=k) continue;
                if (v2[nex] == -1) continue;
                chmin(ans, v[i]+v2[nex]);
            }
        }
        if (ans >= ma) ans = -2;
        cout << ans+1 << endl;
    }


    return 0;
}