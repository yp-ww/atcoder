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

int op1(int a, int b){ return max(a,b); };
int e1(){ return 0; };
int op2(int a, int b){ return min(a,b); };
int e2(){ return 1000000000; };

int main()
{
    int n,m;
    cin>>n>>m;

    segtree<int,op1,e1> seg1(m+1);
    segtree<int,op2,e2> seg2(m+1);

    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        int ma = seg1.get(a);
        if (ma < b) seg1.set(a, b);
        int mi = seg2.get(a);
        if (mi > b) seg2.set(a, b);
    }

    vector<int> ans(m+2);
    rep(i,1,m+1){
        int ng = i-1;
        int ok = m+1;
        while (ok-ng>1){
            int mid = (ng+ok)/2;
            int rmax = seg1.prod(mid+1, m+1);     
            int lmax = seg1.prod(0,i);
            int lmin = seg2.prod(0,i);
            bool flag = true;
            if (lmin < i) flag = false;
            if (lmax > mid) flag = false;
            if (rmax > mid) flag = false;
            if (flag){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        if (ng==m) continue;
        ans[ok-i+1]++;
        ans[m-i+2]--;
    }
    rep(i,1,m+1){
        ans[i] += ans[i-1];
    }
    rep(i,1,m+1){
        cout << ans[i] << endl;
    }


    return 0;
}