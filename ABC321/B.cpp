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
    int n,x;
    cin>>n>>x;
    vector<int>a(n-1);
    rep(i,0,n-1)cin>>a[i];

    sort(all(a));
    int now = 0;
    rep(i,1,n-2){
        now+=a[i];
    }

    int ans = 0;
    if (now+a[0]>=x){
        ans = 0;
        cout << ans << endl;
        return 0;
    }else if(now+a[n-2]<x){
        cout << -1 << endl;
        return 0;
    }else{
        rep(i,a[0],a[n-2]+1){
            if (now+i==x){
                cout << i << endl;
                return 0;
            }
        }
    }


    return 0;
}