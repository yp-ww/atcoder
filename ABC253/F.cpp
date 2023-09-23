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

ll op(ll a, ll b){ return a + b; }
ll e(){ return 0LL; }

int main()
{
    ll n,m,q;
    cin>>n>>m>>q;
    vector<ll> c(n),s(n);

    vector<tuple<int,int,int,ll>> query;
    rep(i,0,q){
        int type;
        cin>>type;
        if (type==1){
            int l, r;
            ll x;
            cin>>l>>r>>x;
            l--; r--;
            query.push_back({type,l,r,x});
        }else if(type==2){
            int idx;
            ll x;
            cin>>idx>>x;
            idx--;
            query.push_back({type,idx,x,0});
        }else{
            int i,j;
            cin>>i>>j;
            i--; j--;
            query.push_back({type,i,j,0});
        }
    }
    vector<queue<pair<int,int>>> last(n);
    vector<vector<pair<int,int>>> watch(q);
    rrep(i, q-1, 0){
        auto [type,a,b,c] = query[i];
        if (type==3){
            last[a].push({b,i});
        }else if(type==2){
            if (last[a].empty()) continue;
            while (!last[a].empty()){
                auto [j,num] = last[a].front(); last[a].pop();
                watch[i].push_back({j,num});
            }
        }
    }
    segtree<ll, op, e> seg(m+1);
    vector<ll> ans(q);
    rep(i,0,q){
        auto [type,a,b,c] = query[i];
        if (type==1){
            ll nowa = seg.get(a);
            ll nowb = seg.get(b+1);
            seg.set(a,nowa+c);
            seg.set(b+1,nowb-c);
        }else if(type==2){
            if (watch[i].size()==0) continue;
            for (auto [j,num]: watch[i]){
                ll temp = seg.prod(0,j+1);
                ans[num]=b-temp;
            }
        }else{
            ll temp = seg.prod(0,b+1);
            cout << ans[i]+temp << endl;
        }
    }



    return 0;
}