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
    int N, M;
    cin >> N >> M;

    vector<vector<tuple<ll,int,int>>> G(N);
    rep(i, 0, M){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({c,b,i+1});
        G[b].push_back({c,a,i+1});
    }

    priority_queue<tuple<ll,int,int>> hq;
    hq.push({0, 0, -1});
    vector<ll> v(N, INF);
    vector<int> ans;
    while (!hq.empty()){
        auto [dis, now, num] = hq.top(); hq.pop();
        if (v[now] != INF) continue;
        dis *= -1;
        v[now] = dis;
        if (num != -1) ans.push_back(num);
        for (auto [c, nex, idx]: G[now]){
            if (v[nex] != INF) continue;
            hq.push({-(dis+c), nex, idx});
        }
    }
    rep(i, 0, N-1){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}