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
    int n;
    cin>>n;
    vector<int>p(n),q(n), qpos(n);
    rep(i,0,n)cin>>p[i];
    rep(i,0,n)cin>>q[i];
    rep(i,0,n){p[i]--; q[i]--;}
    rep(i,0,n) qpos[q[i]] = i;

    vector<int> left(n,-1),right(n,-1);
    // p: [l, r], q: [L, R]
    function<bool(int,int,int,int)> dfs = [&](int l, int r, int L, int R){
        int root = p[l];
        int pos = qpos[root];
        if (pos < L || R < pos) return false;
        if (L < pos){
            left[root] = p[l+1];
            if (!dfs(l+1, l+pos-L, L, pos-1)) return false;
        }
        if (pos < R){
            right[root] = p[l+pos-L+1];
            if (!dfs(l+pos-L+1, r, pos+1, R)) return false;
        }
        return true;
    };

    if (p[0] != 0){
        cout << -1 << endl;
        return 0;
    }

    if (!dfs(0,n-1,0,n-1)){
        cout << -1 << endl;
        return 0;
    }

    rep(i,0,n){
        cout << left[i]+1 << " " << right[i]+1 << endl;
    }

    return 0;
}