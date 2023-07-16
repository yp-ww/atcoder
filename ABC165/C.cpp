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

int N, M, Q;
vector<vector<int>> vec;

void f(vector<int> arr){
    if (arr.size() == N){
        vec.push_back(arr);
        return ;
    }
    auto itr = arr.end();
    itr--;
    auto last = *itr;
    rep(i, last, M+1){
        arr.push_back(i);
        f(arr);
        arr.erase(arr.end() - 1);
    }
    return ;
}


int main()
{
    cin >> N >> M >> Q;
    vector<int> A(Q), B(Q), C(Q), D(Q);
    rep(i, 1, M+1) f(vector<int>{i});
    
    rep(i, 0, Q) cin >> A[i] >> B[i] >> C[i] >> D[i];
       
    int ans = 0;
    for (auto arr: vec){
        int temp = 0;
        rep(i, 0, Q){
            int a, b, c, d;
            a = A[i]; b = B[i]; c = C[i]; d = D[i];
            a--; b--;
            if (arr[b] - arr[a] == c) temp += d;
        }
        chmax(ans, temp);
    }

    cout << ans << endl;

    return 0;
}