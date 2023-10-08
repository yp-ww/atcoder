#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e15;

int main()
{
    vector<string>s(3);
    rep(i,0,3) cin>>s[i];
    set<char> st;
    rep(i,0,3){
        rep(j,0,s[i].size()){
            st.insert(s[i][j]);
        }
    }
    if (st.size()>10){
        cout << "UNSOLVABLE" <<endl;
        return 0;
    }
    vector<char> arr;
    for (auto x: st){
        arr.push_back(x);
    }
    while (arr.size()<10){
        arr.push_back('?');
    }
    sort(all(arr));
    do{
        vector<ll> res(3);
        map<char,ll> mp;
        rep(i,0,10){
            mp[arr[i]] = i;
        }
        bool flag = false;
        rep(i,0,3){
            ll sz = s[i].size();
            rep(j,0,sz){
                if (j==0) if(mp[s[i][j]]==0) flag = true;
                res[i] += mp[s[i][j]]*pow(10,sz-j-1);
            }
            if (flag) break;
        }
        if (flag) continue;
        if (res[0]+res[1]==res[2]){
            rep(i,0,3){
                cout << res[i] << endl;
            }
            return 0;
        }
    }while(next_permutation(all(arr)));

    cout << "UNSOLVABLE" <<endl;

    return 0;
}