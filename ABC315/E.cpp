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
    int N;
    cin >> N;
    vector<vector<int>> P(N);
    rep(i, 0, N){
        int c;
        cin >> c;
        rep(j, 0, c){
            int p;
            cin >> p;
            p--;
            P[i].push_back(p);
        }
    }

    vector<int> indeg(N, 0), v(N, 0);
    vector<vector<int>> G(N);
    
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int now = q.front(); q.pop();
        if (v[now]) continue;
        v[now] = 1;
        for (auto p: P[now]){          
            G[p].push_back(now);
            indeg[now]++;
            q.push(p);
        }
    }

    vector<bool> vis(N);
    vector<int> ans;
    rep(i, 0, N){
        if (indeg[i] == 0 && v[i] == 1){
            q.push(i);
            vis[i] = true;
        }
    }

    while (!q.empty()){
        int now = q.front(); q.pop();
        ans.push_back(now);
        for (auto nex: G[now]){
            if (vis[nex]) continue;
            indeg[nex]--;
            if (indeg[nex] == 0) { q.push(nex); vis[nex] = true; }
        }
    }

    rep(i, 0, ans.size()-1){
        cout << ans[i]+1 << " ";
    }
    cout << endl;

    return 0;
}