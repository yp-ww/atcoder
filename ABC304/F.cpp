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

int main()
{
    int n;
    cin>>n;
    string s;
    cin >> s;

    vector<int> d = {1};
    for (int i=2; i*i<=n; i++){
        if (n%i) continue;
        d.push_back(i);
        if (n/i != i) d.push_back(n/i);
    }
    sort(all(d));

    mint ans = 0;
    vector<mint> cnt(n);

    for (auto x: d){
        mint temp = 1;
        rep(i,0,x){
            int pos = i;
            bool flag = true;
            while (pos < n){
                if (s[pos] == '.'){
                    flag = false;
                    break;
                }
                pos += x;
            }
            int c = 1;
            if (flag) c = 2;
            temp *= c;
        }
        cnt[x] = temp;
        ans += temp;
    }

    for (auto x: d){
        for (auto y: d){
            if (x>=y) continue;
            if (y%x == 0){
                ans -= cnt[x];
                cnt[y] -= cnt[x];
            }
        }
    }

    cout << ans.val() << endl;
    return 0;
}