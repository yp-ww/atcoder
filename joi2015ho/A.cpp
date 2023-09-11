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
    vector<int> P(M);
    rep(i, 0, M) cin >> P[i];

    vector<ll> S(N-1), A(N-1), B(N-1), C(N-1);
    rep(i, 0, N-1){
        ll a, b, c;
        cin >> a >> b >> c;
        A[i] = a; B[i] = b; C[i] = c;
        ll l = 0;
        ll r = 10000000;
        while (r - l > 1){
            ll mid = (l + r) / 2;
            if ((ll)(a*mid) >= (ll)(b*mid+c)){
                r = mid;
            }else{
                l = mid;
            }
        }
        S[i] = r;
    }

    vector<ll> cum(N);
    rep(i, 0, M-1){
        int now = P[i];
        int nex = P[i+1];
        now--; nex--;
        if (nex > now){
            cum[now]++;
            cum[nex]--;
        }else{
            cum[now]--;
            cum[nex]++;
        }
    }
    rep(i, 0, N-1){
        cum[i+1] += cum[i];
    }

    ll ans = 0;
    rep(i, 0, N-1){
        if (cum[i] >= S[i]){
            ans += B[i] * cum[i] + C[i];
        }else{
            ans += A[i] * cum[i];
        }
    }
    cout << ans << endl;

    return 0;
}