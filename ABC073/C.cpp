#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N;
    cin >> N;
    set<ll> st;
    rep(i, 0, N){
        ll a;
        cin >> a;
        if (st.find(a) == st.end()){
            st.insert(a);
        }else{
            st.erase(a);
        }
        
    }

    cout << st.size() << endl;
    return 0;
}