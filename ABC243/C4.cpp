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
    vector<ll> X(N), Y(N);
    string S;
    rep(i, 0, N) cin >> X[i] >> Y[i];
    cin >> S;

    map<ll, vector<pair<ll, char>>> mp;
    rep(i, 0, N){
        mp[Y[i]].push_back(make_pair(X[i], S[i]));
    }
    for (auto p: mp){
        sort(p.second.begin(), p.second.end());
        int c = p.second.size();
        rep(i, 0, c-1){
            if (p.second[i].second == 'R' && p.second[i+1].second == 'L'){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}