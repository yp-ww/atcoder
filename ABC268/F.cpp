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
    vector<string> s(n);
    rep(i,0,n)cin>>s[i];

    vector<tuple<int,ll,ll>> tp;
    ll cum = 0;
    rep(i,0,n){
        ll cntx = 0;
        ll tot = 0;
        rep(j,0,s[i].size()){
            if (s[i][j] == 'X'){
                cntx++;
            }else{
                tot += s[i][j]-'0';
                cum += s[i][j]-'0';
            }
        }
        tp.push_back({i,cntx,tot});
    }

    auto cmp = [](tuple<int,ll,ll> a, tuple<int,ll,ll> b){
        auto [idxa, cnta, tota] = a;
        auto [idxb, cntb, totb] = b;
        ll sa = cnta * totb;
        ll sb = cntb * tota;
        if (sa < sb){
            return a < b;
        }else{
            return a > b;
        }
    };

    stable_sort(all(tp), cmp);
    ll ans = 0;
    for (auto [i, a, b]: tp){
        rep(j,0,s[i].size()){
            if (s[i][j] == 'X'){
                ans += cum;
            }else{
                cum -= s[i][j]-'0';
            }
        }
    }
    cout << ans << endl;

    return 0;
}