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
    vector<vector<int>> S(M);
    rep(i, 0, M){
        int k;
        cin >> k;
        rep(j, 0, k){
            int s;
            cin >> s;
            s--;
            S[i].push_back(s);
        }
    }
    vector<int> P(M);
    rep(i, 0, M) cin >> P[i];

    int ans = 0;
    rep(k, 0, 1<<N){
        bool flag = true;
        rep(i, 0, M){
            int cnt = 0;
            for (auto x: S[i]){
                if (k>>x & 1) cnt++;
            }
            if (cnt%2 != P[i]) flag = false;
        }
        if (flag) ans++;
    }
    cout << ans << endl;

    return 0;
}