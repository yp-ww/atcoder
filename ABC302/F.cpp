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
    
    int MAX = 500100;
    vector<vector<int>> G(N+MAX);

    rep(i, 0, N){
        int a;
        cin >> a;
        rep(j, 0, a){
            int s;
            cin >> s;
            G[s+N].push_back(i);
            G[i].push_back(s+N);
        }
    }

    if (G[1+N].size() == 0 || G[M+N].size() == 0){
        cout << -1 << endl;
        return 0;
    }

    vector<int> v(N+MAX, -1);
    queue<int> q;
    for (auto x: G[1+N]){
        q.push(x);
        v[x] = 0;
    }

    while (!q.empty()){
        int now = q.front(); q.pop();
        for (auto nex: G[now]){
            if (v[nex] != -1) continue;
            v[nex] = v[now] + 1;
            q.push(nex);
        }
    }

    if (v[M+N] == -1){
        cout << -1 << endl;
    }else{
        cout << (v[M+N]-1)/2 << endl;
    }
    


    return 0;
}