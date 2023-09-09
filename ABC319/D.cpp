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
    vector<ll> L(N);
    rep(i, 0, N) cin >> L[i];

    auto f = [&](ll m){
        ll now = 0;
        int cnt = 0;
        rep(i, 0, N){
            if (L[i] > m){
                return false;
            }
            now += L[i];
            if (now > m){
                cnt++;
                now = L[i];
                now++;
                continue;
            }else{
                now++;
                if (now > m){
                    cnt++;
                    now = 0;
                }
            }
        }
            
        if (now) cnt++;
        if (cnt > M){
            return false;
        }else{
            return true;
        }
    };


    ll l = 0LL;
    ll r = (ll)1e18;
    while (r - l > 1){
        ll mid = (l + r) / 2;
        if (f(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }

    cout << r << endl;

    return 0;
}