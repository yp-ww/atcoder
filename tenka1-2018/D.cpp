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

    int K = 0;
    rep(i, 1, N+10){
        if (i*(i-1) == N*2){
            K = i;
            break;
        }
    }
    if (K == 0){
        cout << "No" << endl;
        return 0; 
    }

    int cnt = 0;
    vector<vector<int>> ans(K);
    rep(i, 0, K) rep(j, i+1, K){
        cnt++;
        ans[i].push_back(cnt);
        ans[j].push_back(cnt);
    }

    cout << "Yes" << endl;
    cout << K << endl;
    rep(i, 0, K){
        cout << ans[i].size();
        for (auto a: ans[i]){
            cout << " " << a;
        }
        cout << endl;
    }




    return 0;
}