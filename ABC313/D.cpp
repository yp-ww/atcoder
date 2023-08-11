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
    int N, K;
    cin >> N >> K;

    vector<int> arr(N+1);
    rep(i, 1, K+2){
        cout << '?';
        rep(j, 1, K+2){
            if (j != i) cout << ' ' << j;
        }
        cout << endl;
        cin >> arr[i];
    }

    int tot = 0;
    rep(i, 1, K+2){
        tot += arr[i];
        tot %= 2;
    }

    vector<int> ans(N+1);
    rep(i, 1, K+2){
        ans[i] = ((tot - arr[i])%2 + 2)%2;
    }

    int temp = 0;
    rep(i, 1, K){
        temp += ans[i];
        temp %= 2;
    }

    rep(i, K+2, N+1){
        cout << '?';
        rep(j, 1, K){
            cout << ' ' << j;
        }
        cout << ' ' << i;
        cout << endl;
        int res;
        cin >> res;
        ans[i] = ((res - temp)%2 + 2) % 2;
    }

    cout << '!';
    rep(i, 1, N+1){
        cout << ' ' << ans[i];
    }
    cout << endl;

    return 0;
}