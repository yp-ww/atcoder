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

int op(int a, int b) { return a + b; }
int e() { return 0; }

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> A(N, vector<ll>(M));
    vector<ll> arr;
    rep(i, 0, N) rep(j, 0, M){
        ll a;
        cin >> a;
        arr.push_back(a);
        A[i][j] = a;
    }
    sort(all(arr));
    map<ll, int> mp;
    rep(i, 0, N*M){
        mp[arr[i]] = i;
    }

    segtree<int, op, e> seg(N*M);
    ll ans = 0;
    rep(i, 0, N){
        rep(j, 0, M){
            int s = mp[A[i][j]];
            ans += seg.prod(s, N*M);
        }
        rep(j, 0, M){
            int s = mp[A[i][j]];
            seg.set(s, 1);
        }
    }

    ans += (ll)(N*(N-1)/2) * (ll)(M*(M+1)/2);
    cout << ans << endl;


    return 0;
}