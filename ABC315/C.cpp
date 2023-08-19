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
    ll N;
    cin >> N;
    vector<ll> F(N), S(N);
    rep(i, 0, N) cin >> F[i] >> S[i];

    vector<pair<ll, int>> arr;
    rep(i, 0, N){
        arr.push_back({S[i], F[i]});
    }
    sort(all(arr));

    ll temp = arr[N-1].first;
    int p = arr[N-1].second;
    ll ans = temp;
    rrep(i, N-2, 0){
        if (arr[i].second != p){
            chmax(ans, temp + arr[i].first);
            break;
        }else{
            chmax(ans, temp + arr[i].first / 2);
        }
    }

    cout << ans << endl;
    



    return 0;
}