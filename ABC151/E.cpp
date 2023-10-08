#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e15;

// k ≤ n ≤ 10^7  で法Pが素数のとき
const long long MOD = (long long)1e9+7;
vector<long long> fact, fact_inv, inv;
// init_nCk: 二項係数のための前処理
// 前処理の計算量: O(n)
void init_nCk(int SIZE) {
    fact.resize(SIZE + 5);
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
    }
}
// nCk: MODでの二項係数を求める(前処理 int_nCk が必要)
// クエリ計算量: O(1)
long long nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return fact[n] * (fact_inv[k] * fact_inv[n-k] % MOD) % MOD;
}

using mint = modint1000000007;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];
    sort(all(a));
    
    init_nCk(n+1);
    mint ans = 0;
    rep(i,0,n){
        ll dif = n-(i+1);
        if (dif<k-1) continue;
        ans += -a[i]*nCk(dif,k-1);
    }
    rrep(i,n-1,0){
        ll dif = i;
        if (dif<k-1) continue;
        ans += a[i]*nCk(dif,k-1);
    }
    cout << ans.val() << endl;


    return 0;
}