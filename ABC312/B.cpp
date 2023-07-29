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
const ll INF = (ll)1e15;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, 0, N){
        cin >> S[i];
    }

    rep(i, 0, N) rep(j, 0, M){
        if (i+9>N)continue;
        if (j+9>M)continue;
        bool flag =true;
        rep(a, i, i+4) rep(b, j, j+4){
            if (a<0 || a>=N) continue;
            if (b<0 || b>=M) continue;
            if (i <= a && a < i+3 && j <= b && b < j+3){
                if (S[a][b] == '.') flag = false;
            }else{
                if (S[a][b] == '#') flag = false;
            }
            
        }
        rep(a, i+5, i+9) rep(b, j+5, j+9){
            if (a<0 || a>=N) continue;
            if (b<0 || b>=M) continue;
            if (i+6 <= a && a < i+9 && j+6 <= b && b < j+9){
                if (S[a][b] == '.') flag = false;
            }else{
                if (S[a][b] == '#') flag = false;
            }
        }

        if (flag){
            cout << i+1 << " " << j+1 << endl;
        }
    }


    return 0;
}