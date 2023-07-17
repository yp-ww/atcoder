#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()

const double pi = 3.141592653589793;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    ll L, Q;
    cin >> L >> Q;
    
    set<ll> st;

    rep(i, 0, Q){
        int c;
        ll x;
        cin >> c >> x;
        if (c == 1){
            st.insert(x);
        }else{
            if (st.size() == 0){
                cout << L << endl;
                continue;
            }
            auto itr = st.lower_bound(x);
            if (itr == st.begin()) {
                cout << *itr << endl;
            }else if (itr == st.end()){
                itr--;
                cout << L - *itr << endl;
            }else{
                ll d = *itr;
                itr--;
                d -= *itr;
                cout << d << endl;
            }
        }
    }

    return 0;
}