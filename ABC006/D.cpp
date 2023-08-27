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

int op(int a, int b){return max(a, b);}
int e(){return 0;}

int main()
{
    int N;
    cin >> N;
    vector<int> C(N);
    rep(i, 0, N) cin >> C[i];

    segtree<int, op, e> seg(40000);
    int cnt = 0;
    rep(i, 0, N){
        int temp = seg.prod(0, C[i]);
        seg.set(C[i], temp+1);
    }
    
    int ans = N - seg.prod(0, 40000);
    cout << ans << endl;
    return 0;
}