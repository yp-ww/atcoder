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

int op(int a, int b){ return max(a, b); }
int e(){ return 0; }

int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    map<ll, int> mp;
    set<ll> st;
    rep(i, 0, N){
        st.insert(A[i]);
    }

    int cnt = 0;
    for (auto x: st){
        mp[x] = cnt;
        cnt++;
    }

    segtree<int, op, e> seg(N);

    rep(i, 0, N){
        int temp = seg.prod(mp[A[i]], N);
        seg.set(mp[A[i]], temp+1);
    }

    int ans = seg.prod(0, N);
    cout << ans << endl;
    

    return 0;
}