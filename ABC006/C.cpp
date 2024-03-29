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
    int N;
    cin >> N;
    set<int> st;
    rep(i, 0, N){
        int w;
        cin >> w;
        if (st.lower_bound(w) == st.end()){
            st.insert(w);
        }else{
            auto itr = st.lower_bound(w);
            if (*itr == w) continue;
            st.erase(*itr);
            st.insert(w);
        }
    }
    cout << st.size() << endl;
    return 0;
}