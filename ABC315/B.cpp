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
    int M;
    cin >> M;
    vector<int> D(M);
    rep(i, 0, M) cin >> D[i];
    int tot = 0;
    rep(i, 0, M) tot += D[i];
    tot += 1;
    int pos = tot / 2;
    int now = 0;
    rep(i, 0, M){
        if (now + D[i] < pos){
            now += D[i];
        }else{
            cout << i+1 << " "<< pos - now << endl;
            return 0;
        }
    } 
    return 0;
}