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
    int T;
    cin >> T;

    rep(_, 0, T){
        int N, M;
        cin >> N >> M;
        vector<int> C(N);
        rep(i, 0, N) cin >> C[i];
        vector<vector<int>> G(N);
        rep(i, 0, M){
            int u, v;
            cin >> u >> v;
            u--; v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if (C[0] == C[N-1]){
            cout << -1 << endl;
            continue;
        }
        vector<vector<int>> v(N, vector<int>(N, -1));
        queue<pair<int,int>> q;
        q.push({0, N-1});
        v[0][N-1] = 0;
        while (!q.empty()){
            auto p = q.front(); q.pop();
            int a = p.first;
            int b = p.second;
            for (auto an: G[a]){
                for (auto bn: G[b]){
                    if (C[an] == C[bn]) continue;
                    if (v[an][bn] != -1) continue;
                    v[an][bn] = v[a][b] + 1;
                    q.push({an, bn});
                }
            }
        }
        cout << v[N-1][0] << endl;


    }

    return 0;
}