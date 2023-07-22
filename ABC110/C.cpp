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
    string S, T;
    cin >> S >> T;

    int N = S.size();
    set<char> st;
    map<char, char> mp, mp2;
    rep(i, 0, N){
        char s, t;
        s = S[i];
        t = T[i];
        if (mp.find(s) != mp.end()){
            if (mp[s] != t){
                cout << "No" << endl;
                return 0;
            }
        }else{
            mp[s] = t;
        }

        if (mp2.find(t) != mp2.end()){
            if (mp2[t] != s){
                cout << "No" << endl;
                return 0;
            }
        }else{
            mp2[t] = s;
        }

    }

    cout << "Yes" << endl;
    return 0;
}