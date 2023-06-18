#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N, M, K, Q;
using Graph = vector<vector<int>>;
int v[200200];
set<tuple<int, int>> st;

int main()
{
    Graph G(200200);
    cin >> N >> M;
    for (int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cin >> K;
    int cnt = 0;
    for (int i=0; i<K; i++){
        int x, y;
        cin >> x >> y;
        if (!v[x]){
            cnt += 1;
            v[x] = cnt;
            queue<int> q;
            q.push(x);
            while (!q.empty()){
                int now = q.front();
                for (auto nex: G[now]){
                    if (v[nex]) continue;
                    v[nex] = cnt;
                    q.push(nex);
                }
                q.pop();
            }
        }

        if (!v[y]){
            cnt += 1;
            v[y] = cnt;
            queue<int> q;
            q.push(y);
            while (!q.empty()){
                int now = q.front();
                for (auto nex: G[now]){
                    if (v[nex]) continue;
                    v[nex] = cnt;
                    q.push(nex);
                }
                q.pop();
            }
        }

        int gx = v[x];
        int gy = v[y];
        st.insert(make_tuple(gx, gy));
        st.insert(make_tuple(gy, gx));
    }

    cin >> Q;
    for (int i=0; i<Q; i++){
        int p, q;
        cin >> p >> q;
        if (st.find(make_tuple(v[p], v[q])) != st.end()){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }

    return 0;
}