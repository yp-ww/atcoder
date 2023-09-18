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

    vector<bool> v(N+1);
    vector<vector<int>> G(N+1);

    int now = 1;
    stack<int> s;
    rep(i, 0, 2*N){
        int k;
        cin >> k;
        rep(_, 0, k){
            int x;
            cin >> x;
            if (!v[now]) G[now].push_back(x);
        }
        v[now] = true;
        bool flag = false;
        for (auto nex: G[now]){
            if (v[nex]) continue;
            flag = true;
            s.push(now);
            now = nex;
            break;
        }

        if (!flag){
            now = s.top();
            s.pop();
        }

        cout << now << endl;
        if (now == N){
            break;
        }
    }

    return 0;
}