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

    vector<int> first(n),last(n);
    rep(i,0,n){
        int sz = s[i].size();
        first[i] = s[i][0]-'a';
        last[i] = s[i][sz-1]-'a';
    }

    vector<vector<int>> dp(1<<n, vector<int>(26, 0));
    rep(s,1,1<<n){
        rep(i,0,26){
            rep(j,0,n){
                if (s&(1<<j)){
                    if (first[j] == i){
                        int c = 0;
                        if (dp[s-(1<<j)][last[j]] == 0) c = 1;
                        dp[s][i] += c;
                    }
                }
            }
        }
    }

    bool flag = false;
    rep(i,0,26){
        if (dp[(1<<n)-1][i]) flag = true;
    }
    if (flag){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }

    return 0;
}