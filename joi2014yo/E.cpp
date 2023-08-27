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
    int N, K;
    cin >> N >> K;
    vector<int> C(N), R(N);
    rep(i, 0, N) cin >> C[i] >> R[i];

    vector<vector<int>> G(N);
    rep(i, 0, K){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<vector<int>> fw(N);
    rep(i, 0, N-1){
        queue<int> q;
        q.push(i);
        vector<int> d(N, -1);
        d[i] = 0;
        while (!q.empty()){
            int now = q.front(); q.pop();
            for (auto nex: G[now]){
                if (d[nex] != -1) continue;
                d[nex] = d[now] + 1;
                if (d[nex] < R[i]) q.push(nex);
            }
        }
        rep(j, 0, N){
            if (i == j) continue;
            if (d[j] == -1) continue;
            fw[i].push_back(j);
        }
    }

    priority_queue<pair<ll, int>> hq;
    hq.push({0, 0});
    vector<ll> cost(N, -1);
    while (!hq.empty()){
        auto [tot, now] = hq.top(); hq.pop();
        if (cost[now] != -1) continue;
        tot *= -1;
        cost[now] = tot;
        for (auto nex: fw[now]){
            if (cost[nex] != -1) continue;
            hq.push({-(tot+C[now]), nex});
        }
    }

    cout << cost[N-1] << endl;

    return 0;
}