#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for (int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define all(x) (x).begin(),(x).end()

int main()
{
    ll N, K;
    cin >> N >> K;
    ll A[N], B[N];
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    vector<bool> Aok(N);
    vector<bool> Bok(N);
    Aok[0] = true;
    Bok[0] = true;

    bool flag = true;
    rep(i, 1, N){
        if ((Aok[i-1] && abs(A[i-1]-A[i])<=K) || (Bok[i-1] && abs(B[i-1]-A[i])<=K)){
            Aok[i] = true;
        }
        if ((Aok[i-1] && abs(A[i-1]-B[i])<=K) || (Bok[i-1] && abs(B[i-1]-B[i])<=K)){
            Bok[i] = true;
        }
        if (!(Aok[i] || Bok[i])){
            flag = false;
            break;
        }
    }
    if (flag) cout << "Yes" << endl; else cout << "No" << endl;
    return 0;
}