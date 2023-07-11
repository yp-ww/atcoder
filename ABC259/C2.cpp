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

vector<pair<char, int>> runLengthEncoding(string s){
    int n = s.length();
    vector<pair<char, int>> res;
    int l = 0;
    while (l < n){
        int r = l + 1;
        while (r < n && s[l] == s[r]) r++;
        res.push_back(make_pair(s[l], r-l));
        l = r;
    }
    return res;
}

int main()
{
    string S, T;
    cin >> S >> T;

    auto vs = runLengthEncoding(S);
    auto vt = runLengthEncoding(T);

    if (vs.size() != vt.size()){
        cout << "No" << endl;
        return 0;
    }

    rep(i, 0, vs.size()){
        auto p = vs[i];
        auto q = vt[i];
        if (p.first != q.first){
            cout << "No" << endl;
            return 0;
        }
        if (p.second > q.second || (p.second == 1 && q.second > 1)){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}