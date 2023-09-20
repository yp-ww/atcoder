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
    int N, M;
    cin >> N >> M;

    vector<ll> A(N+1);
    rep(i, 1, N+1) cin >> A[i];


    vector<set<ll>> st(M+1);
    rep(i, 1, N+1){
        ll b = (-A[i]+i-1)/i;
        chmax(b, 0LL);
        while (1){
            if (b <= M){
                ll y = i * b + A[i];
                if (y <= N){
                    st[b].insert(y);
                    b++;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
    }
    rep(i, 1, M+1){
        auto s = st[i];
        ll ans = 0;
        rep(x, 0, N+1){
            if (s.find(x) == s.end()){
                ans = x;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}