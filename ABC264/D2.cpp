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
    string S;
    cin >> S;
    map<char, int> mp;
    rep(i, 0, 7){
        mp["atcoder"[i]] = i;
    }

    vector<int> vc(7);
    rep(i, 0, 7) vc[i] = mp[S[i]];
    int cnt = 0;
    while (1){
        bool flag = false;
        rep(i, 0, 6){
            if (vc[i] > vc[i+1]){
                swap(vc[i], vc[i+1]);
                cnt++;
                flag = true;
            }
        }
        if (!flag) break;
    }

    cout << cnt << endl;

    return 0;
}
