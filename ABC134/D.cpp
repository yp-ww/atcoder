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
    vector<int> A(N+1);
    rep(i, 1, N+1) cin >> A[i];

    vector<int> arr(N+1, 0);
    rrep(i, N, 1){
        int temp = 0;
        int pos = i + i;
        while (pos <= N){
            if (arr[pos] == 1) temp++;
            pos += i;
        }
        temp %= 2;
        if (temp != A[i]) arr[i] += 1;
    }

    int cnt = 0;
    rep(i, 1, N+1){
        if (arr[i] == 1) cnt++;
    }

    cout << cnt << endl;
    rep(i, 1, N+1){
        if (arr[i]) cout << i << " ";
    }

    return 0;
}