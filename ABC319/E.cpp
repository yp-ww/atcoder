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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> P(N), T(N);
    rep(i, 0, N-1) cin >> P[i] >> T[i];
    int Q;
    cin >> Q;
    vector<ll> q(Q);
    rep(i, 0, Q) cin >> q[i];

    int g = 1;
    rep(i, 0, N-1){
        g = lcm(g, P[i]);
    }
    vector<ll> arr(g);
    rep(t, 0, g){
        int now = t;
        ll tot = 0;
        rep(i, 0, N-1){
            int temp = 0;
            rep(j, 0, 8){
                if (((now + j) % P[i]) == 0){
                    temp = j;
                    break;
                }
            }

            tot += temp + T[i];
            now = now + temp + T[i];
            now %= g;
        }
        arr[t] = tot;
    }

    rep(i, 0, Q){
        ll now = q[i];
        now += X;
        now += arr[now%g];
        now += Y;
        cout << now << endl;
    }

    return 0;
}