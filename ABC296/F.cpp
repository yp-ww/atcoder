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

int op(int a, int b){return a+b;}
int e(){return 0;}
int main()
{
    int n;
    cin >> n;
    vector<int>a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    rep(i,0,n){
        a[i]--;b[i]--;
    }

    segtree<int,op,e> sega(n), segb(n);
    vector<int>c=a,d=b;
    sort(all(c));
    sort(all(d));
    bool flag = true;
    rep(i,0,n){
        if (c[i]!=d[i]){
            cout << "No" << endl;
            return 0;
        }
    }

    rep(i,0,n-1){
        if (c[i] == c[i+1] || d[i] == d[i+1]){
            cout << "Yes" << endl;
            return 0;
        }
    }

    int na = 0;
    int nb = 0;
    rep(i,0,n){
        int cnta = sega.prod(0,a[i]);
        int cntb = segb.prod(0,b[i]);
        cnta %= 2;
        cntb %= 2;
        na ^= cnta;
        nb ^= cntb;
        sega.set(a[i],1);
        segb.set(b[i],1);
    }
    YesNo(na == nb);

    return 0;
}