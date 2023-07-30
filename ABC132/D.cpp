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

// k ≤ n ≤ 5000  でPが素数でないとき
const int MAX_N = 5000;
const long long MOD = (long long)1e9+7;
long long COM[MAX_N][MAX_N];
// init_nCk: 二項係数のための前処理
// 前処理の計算量: O(MAX_N*MAX_N)
void init_nCk() {
    memset(COM, 0, sizeof(COM));
    COM[0][0] = 1;
    rep(i, 1, MAX_N){
        COM[i][0] = 1;
        rep(j, 1, MAX_N){
            COM[i][j] = (COM[i-1][j-1] + COM[i-1][j]) % MOD;
        }
    }
}
// nCk: MODでの二項係数を求める(前処理 int_nCk が必要)
// クエリ計算量:O(1)
long long nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return COM[n][k];
}

int main()
{
    int N, K;
    cin >> N >> K;
    int M = N - K;

    init_nCk();

    rep(i, 1, K+1){
        ll ans = 1;
        if (M+1 < i){
            cout << 0 << endl;
            continue;
        }
        // blue
        ans = ans * nCk(K-1, i-1) % MOD;
        // red
        ans = ans * nCk(M+1, i) % MOD;
        cout << ans << endl;        
    }

    return 0;
}