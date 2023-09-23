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
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    rep(i,0,n)cin>>a[i];
    int Ma = 200005;
    vector<int>cnt(Ma);
    
    vector<int> l(q),r(q);
    rep(i,0,q){
        cin>>l[i]>>r[i];
        l[i]--;
    }
    vector<int>qs(q);
    rep(i,0,q)qs[i]=i;
    int d = n/sqrt(q)+1;
    auto cmp = [&](int a, int b){
        if (r[a]/d == r[b]/d){
            return l[a] < l[b];
        }else{
            return r[a] < r[b];
        }
    };
    sort(all(qs), cmp);

    ll ans = 0;
    auto c3 = [](ll n){ return n*(n-1)*(n-2)/6; };
    auto add = [&](int idx){
        int x = a[idx];
        ans -= c3(cnt[x]);
        cnt[x]++;
        ans += c3(cnt[x]);
    };
    auto del = [&](int idx){
        int x = a[idx];
        ans -= c3(cnt[x]);
        cnt[x]--;
        ans += c3(cnt[x]);
    };

    vector<ll>arr(q);
    int nl = 0;
    int nr = 0;
    for(auto i: qs){
        int li = l[i];
        int ri = r[i];
        while(nr<ri){ add(nr); nr++; }
        while(nl>li){ nl--; add(nl); }
        while(nr>ri){ nr--; del(nr); }
        while(nl<li){ del(nl); nl++; }
        arr[i] = ans;
    }
    rep(i,0,q) cout << arr[i] << endl;

    return 0;
}