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
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    ll ans = INF;
    rep(k, 0, 1<<N){
        if (__builtin_popcount(k) != K) continue;
        if (!(k & 1)) continue;
        vector<ll> vec(N);
        rep(i, 0, N){
            vec[i] = A[i];
        }
        ll cost = 0LL;
        rep(i, 1, N){
            if ((k>>i) & 1){
                if (vec[i] <= vec[i-1]){
                    ll dif = vec[i-1] - vec[i] + 1LL;
                    vec[i] += dif;
                    cost += dif;
                }
            }else{
                vec[i] = max(vec[i], vec[i-1]);
            }
        }
        chmin(ans, cost);
    }

    cout << ans << endl;

    return 0;
}