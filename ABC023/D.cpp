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
const ll INF = (ll)1e30;

int main()
{
    int N;
    cin >> N;
    vector<ll> H(N), S(H);
    rep(i, 0, N) cin >> H[i] >> S[i];

    ll l = 0;
    ll r = INF;
    while (r - l > 1){
        ll mid = (l + r) / 2;
        bool flag = true;
        vector<pair<ll, int>> arr;
        rep(i, 0, N){
            if (mid < H[i]) flag = false;
            ll time = (mid - H[i]) / S[i];
            arr.push_back(make_pair(time, i));
        }
        sort(all(arr));
        rep(i, 0, N){
            auto p = arr[i];
            ll time = p.first;
            if (time < (ll)i) flag = false;
        }
        if (flag){
            r = mid;
        }else{
            l = mid;
        }
    }

    cout << r << endl;

    return 0;
}