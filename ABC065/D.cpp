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
    vector<pair<ll, int>> X, Y;
    rep(i, 0, N){
        ll x, y;
        cin >> x >> y;
        X.push_back({x, i});
        Y.push_back({y, i});
    }
    sort(all(X));
    sort(all(Y));
    
    vector<tuple<ll, int, int>> arr;
    rep(i, 0, N-1){
        auto [ax, aidx] = X[i];
        auto [bx, bidx] = X[i+1];
        arr.push_back({abs(ax-bx), aidx, bidx});
    }
    rep(i, 0, N-1){
        auto [ay, aidx] = Y[i];
        auto [by, bidx] = Y[i+1];
        arr.push_back({abs(ay-by), aidx, bidx});
    }

    sort(all(arr));
    ll ans = 0;
    dsu uf(N);
    for (auto [dif, a, b]: arr){
        if (uf.same(a, b)) continue;
        ans += dif;
        uf.merge(a, b);
    }
    cout << ans << endl;


    return 0;
}