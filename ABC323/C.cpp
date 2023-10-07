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
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    rep(i,0,m)cin>>a[i];
    vector<string> s(n);
    rep(i,0,n)cin>>s[i];
    vector<int> now(n);
    int ma = 0;
    vector<vector<int>> rem(n);
    rep(i,0,n){
        rep(j,0,m){
            if (s[i][j] == 'o') now[i] += a[j];
            else rem[i].push_back(a[j]);
        }
        now[i] += i+1;
        chmax(ma, now[i]);
    }
    bool flag = false;
    int cnt = 0;
    rep(i,0,n){
        if (now[i]==ma)cnt++;
    }
    if (cnt>1) flag = true;

    vector<int>ans(n,0);
    rep(i,0,n){
        if (ma == now[i] && !flag){
            ans[i] = 0;
            continue;
        }
        sort(all(rem[i]));
        reverse(all(rem[i]));
        int c = 0;
        rep(j,0,rem[i].size()){
            now[i]+=rem[i][j];
            c++;
            if (now[i]>ma){
                ans[i] = c;
                break;
            }
        }
    
    }
    rep(i,0,n){
        cout << ans[i] << endl;
    }
    return 0;
}