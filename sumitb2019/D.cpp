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
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<vector<int>> cum(10);
    rep(i, 0, N){
        char s = S[i];
        int x = s - '0';
        cum[x].push_back(i+1);
    }

    int ans = 0;
    rep(i, 0, 1000){
        int x1 = (i / 100) % 10;
        int x2 = (i / 10) % 10;
        int x3 = i % 10;
        if (cum[x1].size() == 0) continue;
        int idx1 = cum[x1][0];
        int idx2 = lower_bound(all(cum[x2]), idx1+1) - cum[x2].begin();
        if (idx2 >= cum[x2].size()) continue;
        int idx3 = lower_bound(all(cum[x3]), cum[x2][idx2]+1) - cum[x3].begin();
        if (idx3 >= cum[x3].size()) continue;
        ans++;
        // cout << i << endl;
    }
    cout << ans << endl;

    return 0;
}