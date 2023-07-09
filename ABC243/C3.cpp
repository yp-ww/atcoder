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
    
    map<ll, ll> ml, mr;
    rep(i, 0, N){
        if (S[i] == 'L'){
            if (ml.find(Y[i]) == ml.end()){
                ml[Y[i]] = X[i];
            }else{
                chmax(ml[Y[i]], X[i]);
            }
        }else{
            if (mr.find(Y[i]) == mr.end()){
                mr[Y[i]] = X[i];
            }else{
                chmin(mr[Y[i]], X[i]);
            }
        }
    }
    
    for (auto p : ml){
        if (mr.find(p.first) == mr.end()) continue;
        if (p.second > mr[p.first]){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
