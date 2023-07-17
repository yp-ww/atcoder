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
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    int MAX = 1000100;
    vector<vector<int>> v(MAX+1);

    vector<bool> isprime(MAX+1, true);
    isprime[0] = isprime[1] = false;
    rep(p, 2, MAX+1){
        if (!isprime[p]) continue;
        v[p].push_back(p);
        int q = p + p;
        while (q < MAX+1){
            isprime[q] = false; 
            v[q].push_back(p);
            q += p;
        }
    }

    vector<int> cnt(MAX, 0);
    rep(i, 0, N){
        int a = A[i];
        for (auto p: v[a]){
            cnt[p] += 1;
        }
    }

    bool flag = false;
    rep(p, 2, MAX){
        if (cnt[p] == N){
            cout << "not coprime" << endl;
            return 0;
        }else if(cnt[p] >= 2){
            flag = true;
        }
    }

    if (flag){
        cout << "setwise coprime" << endl;
    }else{
        cout << "pairwise coprime" << endl;
    }

    return 0;
}