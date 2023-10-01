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

using mint = modint998244353;


// combination mod prime
// https://youtu.be/8uowVvQ_-Mo?t=6002
// https://youtu.be/Tgd_zLfRZOQ?t=9928
struct modinv {
    int n; vector<mint> d;
    modinv(): n(2), d({0,1}) {}
    mint operator()(int i) {
        while (n <= i) d.push_back(-d[mint::mod()%n]*(mint::mod()/n)), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i];}
} invs;
struct modfact {
    int n; vector<mint> d;
    modfact(): n(2), d({1,1}) {}
    mint operator()(int i) {
        while (n <= i) d.push_back(d.back()*n), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i];}
} facts;
struct modfactinv {
    int n; vector<mint> d;
    modfactinv(): n(2), d({1,1}) {}
    mint operator()(int i) {
        while (n <= i) d.push_back(d.back()*invs(n)), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i];}
} ifacts;
mint comb(int n, int k) {
    if (n < k || k < 0) return 0;
    return facts(n)*ifacts(k)*ifacts(n-k);
}

int main()
{
    int h,w,k;
    cin>>h>>w>>k;
    
    mint ans = 0;
    vector<vector<mint>> dp(h+1, vector<mint>(w+1,0));
    rep(a,1,h+1)rep(b,1,w+1){
        mint now = 0;
        rep(s,0,1<<4){
            int na = a;
            int nb = b;
            int p = 0;
            if (s&1) { na--; p^=1; }
            if (s&2) { na--; p^=1; } 
            if (s&4) { nb--; p^=1; } 
            if (s&8) { nb--; p^=1; }
            if (na < 0 || nb < 0) continue;
            if (p){
                now += -1 * comb(na*nb, k);
            }else{
                now += comb(na*nb, k);
            }
        }
        ans += now * a * b * (h-a+1) * (w-b+1);
    }
    ans /= comb(h*w, k);
    cout << ans.val() << endl;
    return 0;
}