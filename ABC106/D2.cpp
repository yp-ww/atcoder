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
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> P(N);

    rep(i, 0, M){
        int l, r;
        cin >> l >> r;
        l--; r--;
        P[l].push_back(r);
    }

    rep(i, 0, N){
        sort(all(P[i]));
    }

    rep(i, 0, Q){
        int p, q;
        cin >> p >> q;
        p--; q--;
        int ans = 0;
        rep(j, p, q+1){
            if (P[j].size() == 0) continue;
            auto itr = lower_bound(all(P[j]), q+1);
            int cnt = itr - P[j].begin();
            ans += cnt;
        }
        cout << ans << endl;
    }

    return 0;
}