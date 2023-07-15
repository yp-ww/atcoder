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
 
int N;
ll A[20][20];

vector<pair<int, int>> vec;
bool v[20];

ll calc(){
    if(vec.size() == N){
        ll ans = 0;
        for(auto p : vec) ans ^= (A[p.first][p.second]);
        return ans;
    }
  
    int now;
    rep(i, 0, 2*N){
        if(!v[i]){
            now = i;
            break;
        }
    }
    v[now] = true;

    ll ans = 0;
    rep(nex, now+1, 2*N){
        if (v[nex]) continue;
        vec.push_back(make_pair(now, nex));
        v[nex] = true;
        chmax(ans, calc());
        vec.pop_back();
        v[nex] = false;
    }

    v[now] = false;
    return ans;
}

int main(){
    cin >> N;
    rep(i, 0, 2*N) rep(j, i+1, 2*N) cin >> A[i][j];

    cout << calc() << endl;

    return 0;
}
