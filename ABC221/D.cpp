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
    vector<ll> A(N), B(N);
    set<ll> D;
    rep(i, 0, N){
        cin >> A[i] >> B[i];
        D.insert(A[i]);
        D.insert(A[i] + B[i]);
    }

    map<ll, int> mp;
    auto itr = D.begin();
    rep(i, 0, D.size()){
        mp[*itr] = i;
        itr++;
    }

    vector<ll> cum(D.size()+1, 0);
    rep(i, 0, N){
        ll a = A[i];
        ll b = A[i] + B[i];
        cum[mp[a] + 1] += 1;
        cum[mp[b] + 1] -= 1;
    }

    vector<ll> vc(D.begin(), D.end());
    vector<ll> ans(N+1);
    rep(i, 0, D.size()){
        cum[i+1] = cum[i] + cum[i+1];
        ans[cum[i+1]] += vc[i+1] - vc[i];
    }

    rep(i, 1, N+1){
        cout << ans[i] << " ";
    }

    return 0;
}