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

    vector<vector<pair<int, int>>> G(N);

    dsu uf(N);
    rep(i, 0, K){
        int query;
        cin >> query;
        if (query == 0){
            int a, b;
            cin >> a >> b;
            a--; b--;
            if (uf.same(a, b)){
                priority_queue<pair<int, int>> hq;
                hq.push({0, a});
                int INF = 1000000000;
                vector<int> d(N, INF);
                while (!hq.empty()){
                    auto [dis, now] = hq.top(); hq.pop();
                    if (d[now] != INF) continue;
                    d[now] = -1 * dis;
                    if (now == b) break;
                    for (auto [nex, cost]: G[now]){
                        if (d[nex] != INF) continue;
                        hq.push({-1*(d[now]+cost), nex});
                    }
                }
                cout << d[b] << endl;
            }else{
                cout << -1 << endl;
            }
        }else{
            int c, d, e;
            cin >> c >> d >> e;
            c--; d--;
            G[c].push_back({d, e});
            G[d].push_back({c, e});
            uf.merge(c, d);
        }
    }

    return 0;
}