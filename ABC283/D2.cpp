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

    set<char> st;
    stack<char> q;

    rep(i, 0, S.length()){
        if (S[i] == '('){
            q.push('(');
        }else if (S[i] == ')'){
            while (q.top() != '('){
                st.erase(q.top());
                q.pop();
            }
            q.pop();
        }else{
            if (st.find(S[i]) != st.end()){
                cout << "No" << endl;
                return 0;
            }else{
                st.insert(S[i]);
                q.push(S[i]);
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}