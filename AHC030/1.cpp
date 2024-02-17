#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define smod(n, m) ((((n) % (m)) + (m)) % (m)) // 非負mod
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

inline int popcount(int n) { return __builtin_popcount(n); } // 2進数で表した場合に立ってるビット数がいくつか
inline int popcount(ll n) { return __builtin_popcountll(n); }
inline int ctz(int n) { return n != 0 ? __builtin_ctz(n) : -1; } // 2進数で表した場合に 1 の位からいくつ 0 が連なっているか
inline int ctz(ll n) { return n != 0 ? __builtin_ctzll(n) : -1; }
inline int clz(int n) { return n != 0 ? (31 - __builtin_clz(n)) : -1; } // 2進数で表した場合に左側にいくつ 0 を埋める必要があるか
inline int clz(ll n) { return n != 0 ? (63 - __builtin_clzll(n)) : -1; }

const double PI = 3.141592653589793;
const vector<int> DX = { 1, 0, -1, 0 };
const vector<int> DY = { 0, 1, 0, -1 };
const long long INF = (ll)1e18+10;
ll coordinate(ll h, ll w, ll W){ return h*W + w; } // 二次元座標を一次元座標に変換

// #define endl "\n" // インタラクティブの時はコメントアウトする

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // cout << fixed << setprecision(18);
    
    int N, M, Ep;
    cin >> N >> M >> Ep;
    rep(_, 0, M){
        int d;
        cin >> d;
        rep(k, 0, d){
            int i, j;
            cin >> i >> j;
        }
    }

    // 乱数定義用、選ぶマスの数
    random_device rnd;
    mt19937_64 mt(rnd());
    /* 上限を分散の閾値を設定して決めてもいいかも */
    uniform_int_distribution<> rand(N-5, N+5);

    // 乱数定義用、順列のシャッフル
    mt19937 get_rand_mt;

    // 順列の生成、マスの座標
    vector<int> vec(N*N);
    rep(i, 0, N*N) vec[i] = i;
    
    vector<double> G(N*N);

    // コストが N を超えるまでループ
    double tot_cost = 0;
    int cnt = 0;
    while(tot_cost < (double)N){
        int K = rand(mt);
        cnt++;
        // ランダムに K マス取り出す
        shuffle(all(vec), get_rand_mt);        
        vector<vector<int>> arr; // 選んだマスの格納用
        for (int i=0; i<N*N; i+=K){
            if (i + K > N*N) break;
            cout << "q " << K << " ";
            // 出力
            rep(j, i, i+K){
                cout << vec[j]/N << " " << (vec[j]%N) << " ";
            }
            cout << endl;

            // 入力
            int res;
            cin >> res;

            // 値の分配
            rep(j, i, i+K){
                G[vec[j]] += (double)res/(double)K;
            }
        }
        
        double cost = 1.0/sqrt(K);
        tot_cost += cost;
    }
    
    vector<pair<double,int>> prob(N*N);
    rep(i, 0, N*N){
        prob[i].first = G[i];
        prob[i].second = i;
    }
    sort(all(prob));
    
    
    return 0;
}