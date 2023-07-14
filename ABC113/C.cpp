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
    int N, M;
    cin >> N >> M;

    map<int, vector<pair<ll, int>>> P;
    set<int> st;
    rep(i, 0, M){
        int p;
        ll y;
        cin >> p >> y;
        P[p].push_back(make_pair(y, i));
        st.insert(p);
    }

    for (auto p: st){
        sort(P[p].begin(), P[p].end());
    }

    vector<string> ans(M);
    for (auto p: st){
        rep(i, 0, P[p].size()){
            auto y = P[p][i].first;
            auto idx = P[p][i].second;
            string sp = to_string(p);
            string sx = to_string(i+1);
            sp = string(max(0, 6-(int)sp.size()), '0') + sp;
            sx = string(max(0, 6-(int)sx.size()), '0') + sx;
            ans[idx] = sp + sx;
        }
    }

    rep(i, 0, M){
        cout << ans[i] << endl;
    }

    return 0;
}