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

    ll tot = 0;
    rep(k, 1, N+1){
        tot += (ll)(N-k+1) * (ll)(k/2);        
    }

    vector<vector<int>> arr(N+1);
    rep(i, 0, N){
        int a = A[i];
        arr[a].push_back(i+1);
    }
    
    rep(i, 1, N+1){
        ll sz = arr[i].size();
        if (sz <= 1) continue;
        int l = 0;
        int r = sz-1;
        tot -= (sz*(sz-1))/2;
        ll temp = 0;
        while (l < r){
            ll la = arr[i][l];
            ll ra = arr[i][r];
            if (N-ra <= la-1){
                temp += (N-ra)*(sz-1);
                sz--;
                r--;
            }else{
                temp += (la-1)*(sz-1);
                sz--;
                l++;
            }
        }
        tot -= temp;
    }
    cout << tot << endl;

    return 0;
}