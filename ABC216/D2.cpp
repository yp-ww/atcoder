#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>());
    vector<int> indeg(N);

    rep(i, 0, M){
        int k;
        cin >> k;
        int a;
        cin >> a;
        a--;
        rep(j, 1, k){
            int b;
            cin >> b;
            b--;
            G[a].push_back(b);
            indeg[b] += 1;
            a = b;
        }
    }

    queue<int> q;
    rep(i, 0, N){
        if (!indeg[i]) q.push(i);
    }
    
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (auto nex: G[now]){
            indeg[nex] -= 1;
            if (!indeg[nex]) q.push(nex);
        }
    }

    bool flag = true;
    rep(i, 0, N){
        if (indeg[i]){
            flag = false;
            break;
        }
    }
    
    if (flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}