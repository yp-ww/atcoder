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
    ll N, M;
    cin >> N >> M;

    vector<ll> A(M), B(M);
    rep(i, 0, M) cin >> A[i] >> B[i];

    dsu d(N);
    vector<ll> cnt(M+1);
    cnt[M] = N * (N-1) / 2;
    rrep(i, M-1, 0){
        ll a = A[i];
        ll b = B[i];
        a--; b--;
        ll pre = cnt[i+1];
        if (d.same(a, b)){
            cnt[i] = pre;
            continue;
        }
        ll sa = d.size(a);
        ll sb = d.size(b);
        cnt[i] = pre;
        cnt[i] += sa * (sa-1) / 2;
        cnt[i] += sb * (sb-1) / 2;
        d.merge(a, b);
        ll sz = d.size(a);
        cnt[i] -= sz * (sz-1) / 2;
    }

    rep(i, 1, M+1) cout << cnt[i] << endl;

    return 0;
}