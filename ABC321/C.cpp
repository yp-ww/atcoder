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
    ll k;
    cin >> k;

    if (k <= 10){
        cout << k << endl;
        return 0;
    }
    vector<vector<ll>> arr(12);
    rep(i,0,10){
        arr[1].push_back(i);
    }
    ll cnt=9;

    rep(i,2,12){
        rep(j,1,10){
            for (auto x:arr[i-1]){
                if (i-1==1){
                    if (x >= j) continue;
                }else{
                    if (x/pow(10,i-2)>= j) continue;
                }
                
                ll temp = j*pow(10,i-1)+x;
                arr[i].push_back(temp);
                cnt++;
                if (cnt == k){
                    cout << temp << endl;
                    return 0;
                }
            }
        }

    }



    return 0;
}