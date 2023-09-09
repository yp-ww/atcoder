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
    int N;
    cin >> N;
    string ans = "";
    
    vector<int> arr(10);
    arr[0] = 1;
    rep(i, 1, 10){
        if (N % i) continue;
        if (N < i) continue;
        arr[i] = 1;
    }
 
    rep(i, 0, N+1){
        char temp = '-';
        rep(j, 1, 10){
            if (arr[j] == 0) continue;
            if (i % (N/j) == 0){
                temp = '0' + j;
                break;
            }
        }
        ans += temp;
    }
    cout << ans << endl;
    return 0;
}