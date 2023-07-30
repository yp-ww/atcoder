#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
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
    vector<int> P(N, 0);
    rep(i, 0, M){
        int x, y;
        cin >> x >> y;
        x--; y--;
        P[x] += (1 << y);
        P[y] += (1 << x);
    }
    rep(i, 0, N) P[i] += (1 << i);
    
    int ans = 1;
    rep(k, 0, 1<<N){
        vector<int> gr;
        rep(i, 0, N){
            if ((k>>i) & 1) gr.push_back(i);
        }
        bool flag = true;
        for (auto x: gr){
            for (auto y: gr){
                if (((P[x] >> y) & 1) == 0) flag = false; 
            }
        }
        if (flag){
            int cnt = __builtin_popcount(k);
            chmax(ans, cnt);
        }        
    }

    cout << ans << endl;
    
    return 0;
}