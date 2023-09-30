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
    ll n,m;
    cin>>n>>m;
    vector<ll>x(n),y(n);
    rep(i,0,n)cin>>x[i];
    rep(i,0,n)cin>>y[i];

    vector<tuple<ll,ll,ll>> road;
    rep(i,0,m){
        ll a,b,z;
        cin>>a>>b>>z;
        a--;b--;
        road.push_back({-z,a,b});
    }

    vector<tuple<ll,ll,ll>> air, sea;
    rep(i,0,n){
        air.push_back({-x[i],i,n});
        sea.push_back({-y[i],i,n+1});
    }

    ll ans = INF;
    rep(k,0,4){
        priority_queue<tuple<ll,ll,ll>> hq;
        rep(i,0,n){
            if (k==0){
                hq.push(air[i]);
                hq.push(sea[i]);
            }else if(k==1){
                hq.push(air[i]);             
            }else if(k==2){
                hq.push(sea[i]);             
            }
        }
        rep(i,0,m){
            hq.push(road[i]);
        }

        dsu d(n+10);
        ll temp = 0;
        while (!hq.empty()){
            auto [cost, a, b] = hq.top(); hq.pop();
            cost *= -1;
            if (!d.same(a,b)){
                d.merge(a,b);
                temp += cost;
            }
        }
        if (k==3){
            if (d.size(0) != n) continue;
        }
        chmin(ans, temp);
    }
    cout << ans << endl;

    return 0;
}