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
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<int> arr;
    
    int pos = 1;
    arr.push_back(1);
    while (pos < N){
        int pre = pos - 1;
        if (A[pre] == A[pos]){
            arr.push_back(1);
        }else{
            int c = arr.back();
            arr.pop_back();
            c++;
            arr.push_back(c);
        }
        pos++;
    }

    int ans = 0;
    int sz = arr.size();
    rep(i, 0, sz){
        int temp = arr[i];
        if (i >= 1) temp += arr[i-1];
        if (i+1 < N) temp += arr[i+1];        
        chmax(ans, temp);
    }
    cout << ans << endl;


    return 0;
}