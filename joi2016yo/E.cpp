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
    int N, M, K, S;
    cin >> N >> M >> K >> S;
    int P, Q;
    cin >> P >> Q;
    
    vector<bool> flag(N);
    rep(i, 0, K){
        int c;
        cin >> c;
        c--;
        flag[c] = true;
    }

    vector<vector<int>> G(N);
    rep(i, 0, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> kiken(N, -1);
    queue<int> q;
    rep(i, 0, N){
        if (flag[i]){
            q.push(i);
            kiken[i] = 0;
        }
    }

    while (!q.empty()){
        int now = q.front(); q.pop();
        for (auto nex: G[now]){
            if (kiken[nex] != -1) continue;
            kiken[nex] = kiken[now] + 1;
            if (kiken[nex] < S) q.push(nex); 
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
        for (auto nex: G[now]){
            if (cost[nex] != -1) continue;
            if (flag[nex]) continue;
            if (kiken[nex] == -1){
                hq.push({-(tot+P), nex});
            }else{
                hq.push({-(tot+Q), nex});
            }
        }
    }

    if (kiken[N-1] == -1){
        cout << cost[N-1] - P << endl;
    }else{
        cout << cost[N-1] - Q << endl;
    }    
    
    return 0;
}