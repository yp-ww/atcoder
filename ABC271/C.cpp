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
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    set<int> st;
    rep(i, 0, N) st.insert(A[i]);
    ll INF = (ll)1e10;
    int sz = N - st.size();
    rep(i, 0, sz) st.insert(INF - i);
    
    int ans = 0;
    rep(i, 1, N+1){
        if (st.find(i) != st.end()){ans++; st.erase(i);  continue;}
        if (st.size() < 2) break;
        st.erase(prev(st.end()));
        st.erase(prev(st.end()));
        ans++;
    }

    cout << ans << endl;

    return 0;
}